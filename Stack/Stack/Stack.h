#pragma once
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int StackDataType;

#define MAX_SIZE 100

typedef struct Stack {
	StackDataType arr[MAX_SIZE];
	int top;  // 表示当前个数
} Stack;

// 初始化/销毁
// 增（只能增栈顶）/删（只能删除栈顶）/查（只能查看栈顶）
// 增 -> 顺序表尾插
// 删 -> 顺序表尾删

void StackInit(Stack* pStack);

void StackDestroy(Stack* pStack);

void StackPush(Stack* pStack, StackDataType data);

void StackPop(Stack* pStack);

StackDataType StackTop(const Stack* pStack);

int StackSize(const Stack* pStack);

int StackFull(const Stack* pStack);

int StackEmpty(const Stack* pStack);