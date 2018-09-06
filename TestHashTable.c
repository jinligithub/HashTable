//#include"HashTable.h"
#include"CHashTable.h"
int main()
{
	HashTable ht;
	HashData *pos = NULL;
	HashTableInit(&ht, 10);//初始化哈希表

	HashTableInsert(&ht,"char", "字符");
	HashTableInsert(&ht, "int", "整形");
	HashTableInsert(&ht, "long", "长型");
	HashTableInsert(&ht, "short", "短整形");

	HTPrint(&ht);
	pos=HashTableFind(&ht, "int");
	if (pos !=NULL)
	{
		printf("找到了%s:%s\n",pos->_key,pos->_value);
	}
	else
	{
		printf("找不到\n");
	}
	HashTableRemove(&ht, "int");
	HTPrint(&ht);

	system("pause");
	return 0;
}