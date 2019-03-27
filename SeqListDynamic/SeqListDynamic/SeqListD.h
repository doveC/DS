#pragma once
#include <assert.h>
#include <stdlib.h>

typedef int DataType;

#define INIT_CAPACIT 3

typedef struct SeqListD {
	DataType* arr;
	int capacity;  // 当前的最大容量，相当于静态顺序表的MAXCAPACITY
	int size;  // 当前已使用的容量
} SeqListD;

// 初始化、销毁、所有插入
// 其他和静态顺序表一样

void SeqListDInit(SeqListD *ptr);
void SeqListDDestroy(SeqListD* ptr);
static void ExpandIfRequired(SeqListD* ptr);
void SeqListDPushBack(SeqListD* ptr, DataType data);
void Test();