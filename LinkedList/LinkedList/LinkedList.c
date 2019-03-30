#include "LinkedList.h"

void ListInit(ListNode** pHead) {
	assert(pHead);

	*pHead = NULL;
}

void ListDestroy(ListNode** pHead) {
	assert(pHead);

	*pHead = NULL;
}

void ListPushFront(ListNode** pHead, Datatype data) {
	assert(pHead);

	// 特殊情况，链表为空
	// 和正常情况代码一样
	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = *pHead;

	*pHead = newNode;
}

void ListPushBack(ListNode** pHead, Datatype data) {
	assert(pHead);

	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;

	// 特殊情况，链表为空
	if (*pHead == NULL) {
		*pHead = newNode;
		return;
	}

	// 通常情况
	ListNode* ptr = *pHead;
	while ((ptr->next) != NULL)
		ptr = ptr->next;
	ptr->next = newNode;
}

void ListPopFront(ListNode** pHead) {
	assert(*pHead);  // 不能是空链表
	assert(pHead);

	ListNode* ptr4free = *pHead;
	*pHead = (*pHead)->next;

	free(ptr4free);
}

void ListPopBack(ListNode** pHead) {
	assert(*pHead);  // 不能是空链表
	assert(pHead);

	ListNode* ptr = *pHead;

	// 特殊情况，链表中只有一个节点
	if (ptr->next == NULL) {
		*pHead = NULL;
		free(ptr);
		return;
	}

	// 一般情况
	while ((ptr->next->next) != NULL)
		ptr = ptr->next;
	ListNode* ptr4free = ptr->next;
	ptr->next = NULL;

	free(ptr4free);
}

ListNode* ListFind(ListNode* head, Datatype data) {
	for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next) {
		if (ptr->data == data) {
			return ptr;
		}
	}
	return NULL;
}

// 在节点pos前插入（pos肯定存在于链表中 && pos不是空）
void ListInsert(ListNode** pHead, ListNode* pos, Datatype data) {
	// 头插
	if (*pHead == pos) {
		ListPushFront(pHead, data);
		return;
	}

	// 通常情况
	ListNode* ptr = *pHead;

	// 先找到pos的前一个结点
	while (ptr->next != pos)
		ptr = ptr->next;

	// 插入新节点
	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = pos;
	ptr->next = newNode;
}

void ListErase(ListNode** pHead, ListNode *pos) {
	// 头删
	if (*pHead == pos) {
		ListPopFront(pHead);
		return;
	}

	//一般情况
	ListNode* ptr = *pHead;
	while ((ptr->next) != pos)
		ptr = ptr->next;
	ListNode* ptr4free = ptr->next;
	ptr->next = ptr->next->next;

	free(ptr4free);
}

void print_linkedList(ListNode* head) {
	assert(head);

	ListNode* ptr = head;
	while ((ptr != NULL)) {
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void Test() {
	ListNode* head;
	ListInit(&head);

	ListPushFront(&head, 1);
	ListPushFront(&head, 2);
	ListPushBack(&head, 3);
	ListPushBack(&head, 4);
	print_linkedList(head);

	ListPopFront(&head);
	ListPopBack(&head);
	print_linkedList(head);

	ListNode *res = ListFind(head, 3);
	ListInsert(&head, res, 8);
	print_linkedList(head);

}