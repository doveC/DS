#include "stack.h"

// 1. 实现一个栈，要求实现Push、Pop、Min（返回最小值）的时间复杂度为O(1) （笔记）
typedef struct MinStack {
	Stack stackNormal;
	Stack stackMin;
} MinStack;

void MinStackInit(MinStack* ptr) {
	StackInit(&(ptr->stackNormal));
	StackInit(&(ptr->stackMin));
}

void MinStackPush(MinStack* ptr, StackDataType data) {
	Stack* pNor = &(ptr->stackNormal);
	Stack* pMin = &(ptr->stackMin);

	StackPush(pNor, data);  // Nor栈正常进栈

	if (StackEmpty(pMin)) {  // 如果栈为空，data进栈
		StackPush(pMin, data);
	}
	else if (data < StackTop(pMin)) {  // 如果栈不为空但data比top小，data进栈
		StackPush(pMin, data);
	}
	else {
		StackPush(pMin, StackTop(pMin));  // 栈不为空且data不比top小，top进栈
	}
}

void MinStackPop(MinStack* ptr) {
	StackPop(&(ptr->stackNormal));
	StackPop(&(ptr->stackMin));
}

StackDataType MinStackTop(const MinStack* ptr) {
	return StackTop(&(ptr->stackNormal));
}

StackDataType MinStackMin(const MinStack* ptr) {
	return StackTop(&(ptr->stackMin));
}

void TestMinStack() {
	MinStack stack;

	MinStackInit(&stack);

	StackDataType numbers[] = { 5, 7, 4, 3, 1, 6, 2 };

	for (int i = 0; i < 7; i++) {
		MinStackPush(&stack, numbers[i]);
		printf("Top = %d  Min = %d\n", MinStackTop(&stack), MinStackMin(&stack));
	}
	
	printf("-------\n");

	for (int i = 0; i < 6; i++) {
		MinStackPop(&stack);
		printf("Top = %d  Min = %d\n", MinStackTop(&stack), MinStackMin(&stack));
	}
}

// 2. 两个栈实现一个队列
typedef struct QueueStack {
	Stack stack1;
	Stack stack2;
} QueueS;

void QSInit(QueueS* ptr) {
	StackInit(&(ptr->stack1));
	StackInit(&(ptr->stack2));
}

void QSPush(QueueS* ptr, StackDataType data) {
	// 无脑压栈1
	StackPush(&(ptr->stack1), data);
}

void QSPop(QueueS* ptr) {
	StackDataType data;
	Stack* p1 = &(ptr->stack1);
	Stack* p2 = &(ptr->stack2);

	// 如果栈2为空，从栈1将数据倒过来
	if (StackEmpty(p2)) {
		while (StackEmpty(p1)) {  // 把栈1的所有数据导入栈2
			data = StackTop(p1);
			StackPush(p2, data);
			StackPop(p1);
		}
	}
	StackPop(p2);
}

StackDataType QSTop(QueueS* ptr) {
	StackDataType data;
	Stack* p1 = &(ptr->stack1);
	Stack* p2 = &(ptr->stack2);

	// 如果栈2为空，从栈1将数据倒过来
	if (StackEmpty(p2)) {
		while (!StackEmpty(p1)) {  // 把栈1的所有数据导入栈2
			data = StackTop(p1);
			StackPush(p2, data);
			StackPop(p1);
		}
	}
	
	return StackTop(p2);
}

void TestQS() {
	QueueS qs;
	QSInit(&qs);

	for (int i = 0; i < 10; i++) {
		QSPush(&qs, i);
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", QSTop(&qs));
		QSPop(&qs);
	}
}

// 3. 编程实现判断一个序列的出栈顺序是否合法
// src: a, b, c, d, e, f, g
// out: f, e, g, d, a, c, b
int isLegal(int* src, int srcSize, int* out, int outSize) {
	if (srcSize != outSize)
		return 0;

	int srcIndex = 0;
	int outIndex = 0;
	Stack stack;

	StackInit(&stack);

	while (srcIndex < srcSize) {
		if (src[srcIndex] == out[outIndex]) {
			srcIndex++;
			outIndex++;
		}
		else if (StackSize(&stack) > 0 &&
			StackTop(&stack) == out[outIndex]) {
			StackPop(&stack);
			outIndex++;
		}
		else {
			StackPush(&stack, src[srcIndex]);
			srcIndex++;
		}
	}
	if (outIndex >= outSize) {
		return 1;
	}
	while (outIndex < outSize) {
		if (StackTop(&stack) != out[outIndex]) {
			return 0;
		}
		else {
			outIndex++;
			StackPop(&stack);
		}
	}
	return 1;
}

void TestIsLegal() {

	int src[] = { 1, 2, 3, 4, 5, 6, 7 };
	int out[] = { 5, 6, 4, 7, 2, 3, 1 };
	printf("isLegal = %d\n", isLegal(src, 7, out, 7));
}

// 4. 一个数组实现两个栈
// Solution 1 两边往中间生长
typedef struct {
	int *arr;
	int top1;
	int top2;
	int capacity;
} TStack;

void TStackInit(TStack* pTS) {
	pTS->capacity = 10;
	pTS->arr = (int *)malloc(sizeof(int) * pTS->capacity);
	pTS->top1 = 0;
	pTS->top2 = pTS->capacity - 1;
}

void PStackDestroy(TStack* pTS) {
	free(pTS->arr);
}

void ExpandIfRequired(TStack* pTS) {
	if (pTS->top1 > pTS->top2) {
		// pTS->capacity *= 2;
		int newCapacity = pTS->capacity * 2;
		int* newArr = (int *)malloc(sizeof(int) * newCapacity);

		// 搬运数据
		// 栈1
		for (int i = 0; i < pTS->top1; i++) {
			newArr[i] == pTS->arr[i];
		}

		// 栈2
		int k;
		for (int i = pTS->top2 + 1; i < pTS->capacity; i++) {
			k = i + pTS->capacity;
			newArr[k] = pTS->arr[i];
		}

		pTS->top2 += pTS->capacity;
		pTS->capacity = newCapacity;

		free(pTS->arr);
		pTS->arr = newArr;
	}
}

void Push_1(TStack* pTS, int data) {
	ExpandIfRequired(pTS);

	pTS->arr[pTS->top1] = data;
	pTS->top1++;
}

void Push_2(TStack* pTS, int data) {
	ExpandIfRequired(pTS);

	pTS->arr[pTS->top2] = data;
	pTS->top2--;
}

void Pop_1(TStack* pTS) {
	pTS->top1--;
}

void Pop_2(TStack* pTS) {
	pTS->top2++;
}

int Top_1(TStack* pTS) {
	return pTS->arr[pTS->top1 - 1];
}

int Top_2(TStack* pTS) {
	return pTS->arr[pTS->top2 + 1];
}

int Size_1(TStack* pTS) {
	return pTS->top1;
}

int Size_2(TStack* pTS) {
	return pTS->capacity - pTS->top2 - 1;
}

void TestTStack() {
	TStack stack;
	TStackInit(&stack);

	Push_1(&stack, 1);
	Push_1(&stack, 2);
	Push_1(&stack, 3);
	Push_1(&stack, 4);
	Push_1(&stack, 5);
	Push_1(&stack, 6);
	Push_1(&stack, 7);
	Push_2(&stack, 101);
	Push_2(&stack, 102);
	Push_2(&stack, 103);

	// 触发扩容
	Push_2(&stack, 104);
}

int main() {
	// TestMinStack();
	// TestQS();
	// TestIsLegal();
	TestTStack();

	system("pause");
	return 0;
}
