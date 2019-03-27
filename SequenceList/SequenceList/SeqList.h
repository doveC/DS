#pragma once
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100

typedef int DataType;

typedef struct SeqList {
	DataType array[100];
	int size;  // 保存顺序表里已经存了的数据的个数
}SeqList;


void SeqListInit(SeqList* ptr);
void SeqListDestroy(SeqList* ptr);
void SeqListPuchBack(SeqList* ptr, DataType data);
void SeqListPushFront(SeqList* ptr, DataType data);
void SeqListInsert(SeqList* ptr, DataType data, int index);
void SeqListPopBack(SeqList* ptr);
void SeqListPopFront(SeqList* ptr);
void SeqListDelete_1(SeqList* ptr, int index);
void SeqListDelete_2(SeqList* ptr, DataType data);
void SeqListDeleteAll(SeqList* ptr, DataType data);
int SeqListFind(SeqList* ptr, DataType data);
void SeqListPrint(const SeqList* ptr);
void Test();
