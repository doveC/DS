#pragma once
#include <assert.h>
#include <stdlib.h>

/*
*双向
*循环
*带头
*/

typedef struct DListNode {
	int data;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

// 初始化/销毁
// 清空链表
// 插入
// 删除

void DListInit(DListNode** pHead);
void DListClear(DListNode* head);
void DListDestroy(DListNode** pHead);
void DListInsert(DListNode* head, DListNode* pos, int data);
void DListPushFront(DListNode* head, int data);
void DListPushBack(DListNode* head, int data);
void DListErase(DListNode* head, DListNode* pos);
void DListPopFront(DListNode* head);
void DListPopBack(DListNode* head);
void Test();