#pragma once
#include <assert.h>
#include <stdlib.h>

/*
*˫��
*ѭ��
*��ͷ
*/

typedef struct DListNode {
	int data;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

// ��ʼ��/����
// �������
// ����
// ɾ��

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