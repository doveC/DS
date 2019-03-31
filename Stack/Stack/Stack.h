#pragma once
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int StackDataType;

#define MAX_SIZE 100

typedef struct Stack {
	StackDataType arr[MAX_SIZE];
	int top;  // ��ʾ��ǰ����
} Stack;

// ��ʼ��/����
// ����ֻ����ջ����/ɾ��ֻ��ɾ��ջ����/�飨ֻ�ܲ鿴ջ����
// �� -> ˳���β��
// ɾ -> ˳���βɾ

void StackInit(Stack* pStack);

void StackDestroy(Stack* pStack);

void StackPush(Stack* pStack, StackDataType data);

void StackPop(Stack* pStack);

StackDataType StackTop(const Stack* pStack);

int StackSize(const Stack* pStack);

int StackFull(const Stack* pStack);

int StackEmpty(const Stack* pStack);