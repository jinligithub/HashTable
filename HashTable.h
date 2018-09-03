#pragma once 

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef int HTKeyType;
typedef int HTValueType;
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

void HashTableInit(HashTable*ht,int len);//��ʼ����ϣ��
void HashTableDestory(HashTable*ht);//��ϣ�������
void CheckCapacity(HashTable* ht);//���ݺ���
int HashTableInsert(HashTable*ht, HTKeyType key, HTKeyType value);//��ϣ��Ĳ���
HashData* HashTableFind(HashTable*ht, HTKeyType key);//��ϣ��Ĳ���
int HashTableRemove(HashTable*ht, HTKeyType key);//��ϣ���ɾ��
int HashTableSize(HashTable*ht);//��ϣ��Ĵ�С
int HashTableEmpty(HashTable*ht);//��ϣ���Ƿ�Ϊ��
void HTPrint(HashTable*ht);//��ӡ��ϣ��

