#include "Stack.h"

void StackInit(Stack* pStack) {
	pStack->top = 0;
}

void StackDestroy(Stack* pStack) {
	pStack->top = 0;
}

void StackPush(Stack* pStack, StackDataType data) {
	assert(pStack->top < MAX_SIZE);

	pStack->arr[pStack->top++] = data;
}

void StackPop(Stack* pStack) {
	assert(pStack->top > 0);

	pStack->top--;
}

StackDataType StackTop(const Stack* pStack) {
	assert(pStack->top > 0);

	return pStack->arr[pStack->top - 1];
}

int StackSize(const Stack* pStack) {
	return pStack->top;
}

int StackFull(const Stack* pStack) {
	return pStack->top >= MAX_SIZE;
}

int StackEmpty(const Stack* pStack) {
	return pStack->top <= 0;
}
