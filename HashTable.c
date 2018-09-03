#include"HashTable.h"
void HashTableInit(HashTable *ht,int len)//��ʼ����ϣ��
{
	assert(len > 0);
	assert(ht);
	int i = 0;
	ht->_table = (HashData*)malloc(sizeof(HashData)*len);//���ٱ���Ϊlen�Ŀռ�
	ht->_size = 0;//�տ�ʼû������,�������ݸ���Ϊ0
	ht->_len = len;//��ĳ���
	for (i = 0; i < len; i++)
	{
		ht->_table[i]._state = EMPTY;//�ʼ��û�����ݣ�����״̬��Ϊ��
	}
}
void HashTableDestory(HashTable*ht)//��ϣ�������
{
	assert(ht);
	free(ht->_table);//�ͷű�
	ht->_table = NULL;//��ֹҰָ��ĳ���
	ht->_len = ht->_size = 0;//��ĳ��Ⱥͱ����Ԫ�ظ�����Ϊ0
}
void CheckCapacity(HashTable* ht)//���ݺ���
{
	if (((ht->_size * 10) / ht->_len) >= 7)//��Ϊ��������Ӧ�ÿ�����0.7���£���ΪΪint �ͣ������ȳ�ʮ�����ٳ���
	{
		HashTable* newht = NULL;//����һ���µĹ�ϣ��
		HashTableInit(newht, ht->_len * 2);
		for (int i = 0; i < ht->_len; i++)
		{
			if (ht->_table[i]._state == EXITS)//��֮ǰ���ڵ�Ԫ�ط������
			{
				HashTableInsert(newht, ht->_table[i]._key, ht->_table[i]._value);
			}
		}
		HashTableDestory(ht);//����֮ǰ�ı�
		ht->_table = newht->_table;//���µĹ�ϣ����Ķ������ɹ�ϣ��
		ht->_len = newht->_len;
		ht->_size = newht->_size;
	}
}
int HashFunc(HTKeyType key, size_t len)
{
	return key%len;
}
int HashTableInsert(HashTable *ht, HTKeyType key, HTKeyType value)//��ϣ��Ĳ���
{
	CheckCapacity(ht);//�ж��Ƿ�����
	int index = HashFunc(key,ht->_len);
	while (ht->_table[index]._state != EMPTY)//��state��״̬��ΪEXITSʱ��������ҡ�
	{
		if (ht->_table[index]._key == key)//�ҵ������ݣ����Ҹ������Ѿ�����
			return 0;
		else//û���ҵ������������
			++index;
	}
	ht->_table[index]._state = EXITS;//��key��״̬��Ϊ����
	ht->_table[index]._key = key;
	ht->_table[index]._value = value;
	ht->_size++;
	return 1;
}
HashData* HashTableFind(HashTable*ht, HTKeyType key)//��ϣ��Ĳ���
{
	assert(ht);
	int index = 0;
	index = HashFunc(key, ht->_len);//���ҵ�Ҫ���ҵ�λ��
	while (ht->_table[index]._state != EMPTY)
	{
		if (ht->_table[index]._key == key)//�ҵ���key
		{
			if (ht->_table[index]._state = EXITS)//����key��ֵ���ڣ��ͷ���key
				return &ht->_table[index];
			else//key��ֵ������
				return NULL;
		}
		else
			++index;//���������
	}
	return NULL;//û�ҵ�
}
int HashTableRemove(HashTable*ht, HTKeyType key)//��ϣ���ɾ��
{
	assert(ht);
	int index = 0;
	index = HashFunc(key, ht->_len);//���ҵ�Ҫɾ����λ��
	if (index)
	{
		ht->_table[index]._state = DELETE;//��key��״̬��Ϊɾ��
		ht->_table[index]._key = 0;
	}
	else
	{
		return 0;//û��ɾ��
	}
	return 1;//ɾ���ɹ�
}
int HashTableSize(HashTable*ht)//��ϣ��Ĵ�С
{
	assert(ht);
	return ht->_size;
}
int HashTableEmpty(HashTable*ht)//��ϣ���Ƿ�Ϊ��
{
	assert(ht);
	return ht->_size == 0 ? 0 : 1;//Ϊ�շ���0����Ϊ�շ���1
}
void HTPrint(HashTable *ht)
{
	assert(ht);
	int i = 0;
	for (i = 0; i < ht->_len; i++)
	{
		if (ht->_table[i]._state == EXITS)//��������ʱ��ӡ
			printf("table %d: %d\n", ht->_table[i]._key, ht->_table[i]._value);
		else//Ϊ����״̬�����
			printf("�ջ�ɾ��\n");
	}
	printf("\n");
}

void TestHash()
{
	HashTable ht;
	HashData *pos = NULL;
	HashTableInit(&ht, 10);//��ʼ����ϣ��

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
		printf("�ҵ���\n");
	}
	else
	{
		printf("�Ҳ���\n");
	}
	HashTableRemove(&ht, 5);
	HTPrint(&ht);

}