#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int Datatype;

typedef struct ListNode {
	Datatype data;
	struct ListNode* next;
}ListNode;

typedef struct ComplexListNode {
	Datatype data;
	struct ComplexListNode* next;
	struct ComplexListNode* random;
}ComplexListNode;

void ListInit(ListNode** pHead);
void ListDestroy(ListNode** pHead);
void ListPushFront(ListNode** pHead, Datatype data);
void ListPushBack(ListNode** pHead, Datatype data);
void ListInsert(ListNode** pHead, ListNode* pos, Datatype data);
void ListPopFront(ListNode** pHead);
void ListPopBack(ListNode** pHead);
ListNode* ListFind(ListNode* head, Datatype data);
void print_linkedList(ListNode* head);
void Test();
