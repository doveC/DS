#include "LinkedList.h"

// 判断是否有环
int hasCircle(ListNode* head) {
	ListNode* ptrFast = head;
	ListNode* ptrSlow = head;

	do
	{
		if (ptrFast->next == NULL)
			return 0;
		else if (ptrFast->next->next == NULL)
			return 0;

		ptrFast = ptrFast->next->next;
		ptrSlow = ptrSlow->next;
	} while (ptrFast != ptrSlow);
	return 1;
}

// 寻找环入口
// 输入有环链表
ListNode* findCircleEntry(ListNode* head) {
	ListNode* ptrFast = head;
	ListNode* ptrSlow = head;

	// 寻找相交节点
	do
	{
		ptrFast = ptrFast->next->next;
		ptrSlow = ptrSlow->next;
	} while (ptrFast != ptrSlow);

	// 寻找环入口
	// 这时指针不分快慢，每次都走一步
	// 一个指针到链表入口，一个指针停留在相交位置
	ptrSlow = head;
	while (ptrSlow != ptrFast) {
		ptrSlow = ptrSlow->next;
		ptrFast = ptrFast->next;
	}

	// 此时的相交节点即为环入口
	return ptrSlow;
}

int main() {
	// 建立链表
	ListNode* head;
	ListInit(&head);
	ListPushBack(&head, 1);
	ListPushBack(&head, 2);
	ListPushBack(&head, 3);
	ListPushBack(&head, 4);
	ListPushBack(&head, 5);
	ListPushBack(&head, 6);
	ListPushBack(&head, 7);
	print_linkedList(head);
	printf("%d\n", hasCircle(head));

	// 成环
	ListNode* ptr = head;
	ListNode* tmp = NULL;
	while (ptr->next) {
		if (ptr->data == 3)
			tmp = ptr;
		ptr = ptr->next;
	}
	ptr->next = tmp;
	printf("%d\n", hasCircle(head));

	int res = findCircleEntry(head)->data;
	printf("相交节点：%d\n", res);

	system("pause");
	return 0;
}