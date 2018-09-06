#pragma once 

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef char* HTKeyType;
typedef char* HTValueType;
typedef enum State
{
	EMPTY,//��
	EXITS,//����
	DELETE,//ɾ��
}State;
typedef struct HashData
{
	State _state;//���ݵ�״̬
	HTKeyType _key;//Ԫ�ص�ֵ
	HTKeyType _value;//Ԫ�س��ֵĴ���
}HashData;
typedef struct HashTable
{
	HashData *_table;
	int _len;//��ϣ��ĳ���
	int _size;//����ڹ�ϣ��������ݸ���
}HashTable;

void CHashTableInit(HashTable*ht, int len);//��ʼ����ϣ��
void CHashTableDestory(HashTable*ht);//��ϣ�������
void CCheckCapacity(HashTable* ht);//���ݺ���
int CHashTableInsert(HashTable*ht, HTKeyType key, HTKeyType value);//��ϣ��Ĳ���
HashData* CHashTableFind(HashTable*ht, HTKeyType key);//��ϣ��Ĳ���
int CHashTableRemove(HashTable*ht, HTKeyType key);//��ϣ���ɾ��
int CHashTableSize(HashTable*ht);//��ϣ��Ĵ�С
int CHashTableEmpty(HashTable*ht);//��ϣ���Ƿ�Ϊ��
void CHTPrint(HashTable*ht);//��ӡ��ϣ��
void TestCHash();//���Ժ���