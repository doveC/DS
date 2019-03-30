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

	// �������������Ϊ��
	// �������������һ��
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

	// �������������Ϊ��
	if (*pHead == NULL) {
		*pHead = newNode;
		return;
	}

	// ͨ�����
	ListNode* ptr = *pHead;
	while ((ptr->next) != NULL)
		ptr = ptr->next;
	ptr->next = newNode;
}

void ListPopFront(ListNode** pHead) {
	assert(*pHead);  // �����ǿ�����
	assert(pHead);

	ListNode* ptr4free = *pHead;
	*pHead = (*pHead)->next;

	free(ptr4free);
}

void ListPopBack(ListNode** pHead) {
	assert(*pHead);  // �����ǿ�����
	assert(pHead);

	ListNode* ptr = *pHead;

	// ���������������ֻ��һ���ڵ�
	if (ptr->next == NULL) {
		*pHead = NULL;
		free(ptr);
		return;
	}

	// һ�����
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

// �ڽڵ�posǰ���루pos�϶������������� && pos���ǿգ�
void ListInsert(ListNode** pHead, ListNode* pos, Datatype data) {
	// ͷ��
	if (*pHead == pos) {
		ListPushFront(pHead, data);
		return;
	}

	// ͨ�����
	ListNode* ptr = *pHead;

	// ���ҵ�pos��ǰһ�����
	while (ptr->next != pos)
		ptr = ptr->next;

	// �����½ڵ�
	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = pos;
	ptr->next = newNode;
}

void ListErase(ListNode** pHead, ListNode *pos) {
	// ͷɾ
	if (*pHead == pos) {
		ListPopFront(pHead);
		return;
	}

	//һ�����
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