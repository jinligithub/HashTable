#include"HashTable.h"
void HashTableInit(HashTable *ht,int len)//初始化哈希表
{
	assert(len > 0);
	assert(ht);
	int i = 0;
	ht->_table = (HashData*)malloc(sizeof(HashData)*len);//开辟表长度为len的空间
	ht->_size = 0;//刚开始没有数据,表中数据个数为0
	ht->_len = len;//表的长度
	for (i = 0; i < len; i++)
	{
		ht->_table[i]._state = EMPTY;//最开始还没放数据，所以状态都为空
	}
}
void HashTableDestory(HashTable*ht)//哈希表的销毁
{
	assert(ht);
	free(ht->_table);//释放表
	ht->_table = NULL;//防止野指针的出现
	ht->_len = ht->_size = 0;//表的长度和表里的元素个数置为0
}
void CheckCapacity(HashTable* ht)//增容函数
{
	if (((ht->_size * 10) / ht->_len) >= 7)//因为负载因子应该控制在0.7以下，因为为int 型，所以先乘十，在再除表长
	{
		HashTable* newht = NULL;//创建一个新的哈希表
		HashTableInit(newht, ht->_len * 2);
		for (int i = 0; i < ht->_len; i++)
		{
			if (ht->_table[i]._state == EXITS)//把之前存在的元素放入表中
			{
				HashTableInsert(newht, ht->_table[i]._key, ht->_table[i]._value);
			}
		}
		HashTableDestory(ht);//销毁之前的表
		ht->_table = newht->_table;//把新的哈希表里的东西给旧哈希表
		ht->_len = newht->_len;
		ht->_size = newht->_size;
	}
}
int HashFunc(HTKeyType key, size_t len)
{
	return key%len;
}
int HashTableInsert(HashTable *ht, HTKeyType key, HTKeyType value)//哈希表的插入
{
	CheckCapacity(ht);//判断是否增容
	int index = HashFunc(key,ht->_len);
	while (ht->_table[index]._state != EMPTY)//当state的状态不为EXITS时继续向后找。
	{
		if (ht->_table[index]._key == key)//找到该数据，并且该数据已经存在
			return 0;
		else//没有找到，继续向后找
			++index;
	}
	ht->_table[index]._state = EXITS;//把key的状态改为存在
	ht->_table[index]._key = key;
	ht->_table[index]._value = value;
	ht->_size++;
	return 1;
}
HashData* HashTableFind(HashTable*ht, HTKeyType key)//哈希表的查找
{
	assert(ht);
	int index = 0;
	index = HashFunc(key, ht->_len);//先找到要查找的位置
	while (ht->_table[index]._state != EMPTY)
	{
		if (ht->_table[index]._key == key)//找到了key
		{
			if (ht->_table[index]._state = EXITS)//并且key的值存在，就返回key
				return &ht->_table[index];
			else//key的值不存在
				return NULL;
		}
		else
			++index;//继续向后找
	}
	return NULL;//没找到
}
int HashTableRemove(HashTable*ht, HTKeyType key)//哈希表的删除
{
	assert(ht);
	int index = 0;
	index = HashFunc(key, ht->_len);//先找到要删除的位置
	if (index)
	{
		ht->_table[index]._state = DELETE;//把key的状态改为删除
		ht->_table[index]._key = 0;
	}
	else
	{
		return 0;//没有删除
	}
	return 1;//删除成功
}
int HashTableSize(HashTable*ht)//哈希表的大小
{
	assert(ht);
	return ht->_size;
}
int HashTableEmpty(HashTable*ht)//哈希表是否为空
{
	assert(ht);
	return ht->_size == 0 ? 0 : 1;//为空返回0，不为空返回1
}
void HTPrint(HashTable *ht)
{
	assert(ht);
	int i = 0;
	for (i = 0; i < ht->_len; i++)
	{
		if (ht->_table[i]._state == EXITS)//当它存在时打印
			printf("table %d: %d\n", ht->_table[i]._key, ht->_table[i]._value);
		else//为其他状态的情况
			printf("空或被删除\n");
	}
	printf("\n");
}

void TestHash()
{
	HashTable ht;
	HashData *pos = NULL;
	HashTableInit(&ht, 10);//初始化哈希表

	HashTableInsert(&ht, 1, 10);
	HashTableInsert(&ht, 2, 20);
	HashTableInsert(&ht, 3, 30);
	HashTableInsert(&ht, 4, 40);
	HashTableInsert(&ht, 5, 50);
	HashTableInsert(&ht, 6, 60);

	HTPrint(&ht);
	pos = HashTableFind(&ht, 5);
	if (pos != NULL)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	HashTableRemove(&ht, 5);
	HTPrint(&ht);

}