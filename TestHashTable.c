//#include"HashTable.h"
#include"CHashTable.h"
int main()
{
	HashTable ht;
	HashData *pos = NULL;
	HashTableInit(&ht, 10);//��ʼ����ϣ��

	HashTableInsert(&ht,"char", "�ַ�");
	HashTableInsert(&ht, "int", "����");
	HashTableInsert(&ht, "long", "����");
	HashTableInsert(&ht, "short", "������");

	HTPrint(&ht);
	pos=HashTableFind(&ht, "int");
	if (pos !=NULL)
	{
		printf("�ҵ���%s:%s\n",pos->_key,pos->_value);
	}
	else
	{
		printf("�Ҳ���\n");
	}
	HashTableRemove(&ht, "int");
	HTPrint(&ht);

	system("pause");
	return 0;
}