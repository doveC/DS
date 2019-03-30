#include "LinkedList.h"

// �ж��Ƿ��л�
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

// Ѱ�һ����
// �����л�����
ListNode* findCircleEntry(ListNode* head) {
	ListNode* ptrFast = head;
	ListNode* ptrSlow = head;

	// Ѱ���ཻ�ڵ�
	do
	{
		ptrFast = ptrFast->next->next;
		ptrSlow = ptrSlow->next;
	} while (ptrFast != ptrSlow);

	// Ѱ�һ����
	// ��ʱָ�벻�ֿ�����ÿ�ζ���һ��
	// һ��ָ�뵽������ڣ�һ��ָ��ͣ�����ཻλ��
	ptrSlow = head;
	while (ptrSlow != ptrFast) {
		ptrSlow = ptrSlow->next;
		ptrFast = ptrFast->next;
	}

	// ��ʱ���ཻ�ڵ㼴Ϊ�����
	return ptrSlow;
}

int main() {
	// ��������
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

	// �ɻ�
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
	printf("�ཻ�ڵ㣺%d\n", res);

	system("pause");
	return 0;
}