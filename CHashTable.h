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
	EMPTY,//空
	EXITS,//存在
	DELETE,//删除
}State;
typedef struct HashData
{
	State _state;//数据的状态
	HTKeyType _key;//元素的值
	HTKeyType _value;//元素出现的次数
}HashData;
typedef struct HashTable
{
	HashData *_table;
	int _len;//哈希表的长度
	int _size;//存放在哈希表里的数据个数
}HashTable;

void CHashTableInit(HashTable*ht, int len);//初始化哈希表
void CHashTableDestory(HashTable*ht);//哈希表的销毁
void CCheckCapacity(HashTable* ht);//增容函数
int CHashTableInsert(HashTable*ht, HTKeyType key, HTKeyType value);//哈希表的插入
HashData* CHashTableFind(HashTable*ht, HTKeyType key);//哈希表的查找
int CHashTableRemove(HashTable*ht, HTKeyType key);//哈希表的删除
int CHashTableSize(HashTable*ht);//哈希表的大小
int CHashTableEmpty(HashTable*ht);//哈希表是否为空
void CHTPrint(HashTable*ht);//打印哈希表
void TestCHash();//测试函数