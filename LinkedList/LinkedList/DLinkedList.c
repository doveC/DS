#include "DLinkedList.h"

void DListInit(DListNode** pHead) {
	assert(pHead);
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));

	// ��Щ����£����԰�ͷ�ڵ��һЩ��Ч��Ϣ
	head->next = head;
	head->prev = head;

	*pHead = head;
}

void DListClear(DListNode* head) {
	DListNode* ptr = head->next;
	DListNode* ptr4free;

	while (ptr != head) {
		ptr4free = ptr;
		ptr = ptr->next;
		free(ptr4free);
	}
	head->next = head;
	head->prev = head;
}

void DListDestroy(DListNode** pHead) {
	DListClear(*pHead);
	free(*pHead);
	pHead = NULL;
}

void DListInsert(DListNode* head, DListNode* pos, int data) {
	DListNode* newNode = (DListNode *)malloc(sizeof(DListNode));
	newNode->data = data;

	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev->next = newNode;
	pos->prev = newNode;
}

void DListPushFront(DListNode* head, int data) {
	DListInsert(head, head->next, data);
}

void DListPushBack(DListNode* head, int data) {
	DListInsert(head, head, data);
}

// pos�϶�����ͷ�ڵ�
void DListErase(DListNode* head, DListNode* pos) {
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
}

void DListPopFront(DListNode* head) {
	// ����Ϊ�գ�head->next == head
	DListErase(head, head->next);
}

void DListPopBack(DListNode* head) {
	DListErase(head, head->prev);
}

void Test() {
	DListNode* head;
	DListInit(&head);
}