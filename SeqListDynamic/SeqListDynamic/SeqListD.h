#pragma once
#include <assert.h>
#include <stdlib.h>

typedef int DataType;

#define INIT_CAPACIT 3

typedef struct SeqListD {
	DataType* arr;
	int capacity;  // ��ǰ������������൱�ھ�̬˳����MAXCAPACITY
	int size;  // ��ǰ��ʹ�õ�����
} SeqListD;

// ��ʼ�������١����в���
// �����;�̬˳���һ��

void SeqListDInit(SeqListD *ptr);
void SeqListDDestroy(SeqListD* ptr);
static void ExpandIfRequired(SeqListD* ptr);
void SeqListDPushBack(SeqListD* ptr, DataType data);
void Test();