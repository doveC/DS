#include "Queue.h"

// 1. 两个队列实现一个栈

typedef struct {
	Queue queue_1;
	Queue queue_2;
} QStack;

void QSInit(QStack* pQS) {
	QueueInit(&(pQS->queue_1));
	QueueInit(&(pQS->queue_2));
}

void QSDestroy(QStack* pQS) {
	QueueDestroy(&(pQS->queue_1));
	QueueDestroy(&(pQS->queue_2));
}

// Push / Pop / Top
// 只往非空队列里插入
// 如果两个队列都是空的，就往queue_1里插
void QSPush(QStack* pQS, QDataType data) {
	Queue* pEmpty = &(pQS->queue_2);
	Queue* pNotEmpty = &(pQS->queue_1);
	if (!QueueEmpty(pEmpty)) {
		pEmpty = &(pQS->queue_1);
		pNotEmpty = &(pQS->queue_2);
	}

	QueuePush(pNotEmpty, data);
}

void QSPop(QStack* pQS) {
	Queue* pEmpty = &(pQS->queue_2);
	Queue* pNotEmpty = &(pQS->queue_1);
	if (!QueueEmpty(pEmpty)) {
		pEmpty = &(pQS->queue_1);
		pNotEmpty = &(pQS->queue_2);
	}

	// 不能两个队列都为空
	assert(!QueueEmpty(pNotEmpty));

	// 从非空队列里移动size-1个元素到空队列
	while (QueueSize(pNotEmpty) > 1) {
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}

	// pNotEmpty队列里只剩一个数据
	QueuePop(pNotEmpty);
}

QDataType QSFront(QStack* pQS) {
	Queue* pEmpty = &(pQS->queue_2);
	Queue* pNotEmpty = &(pQS->queue_1);
	if (!QueueEmpty(pEmpty)) {
		pEmpty = &(pQS->queue_1);
		pNotEmpty = &(pQS->queue_2);
	}

	// 不能两个队列都为空
	assert(!QueueEmpty(pNotEmpty));

	// 从非空队列里移动size-1个元素到空队列
	while (QueueSize(pNotEmpty) > 1) {
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}

	// pNotEmpty队列里只剩一个数据
	QDataType res = QueueFront(pNotEmpty);
	QueuePop(pNotEmpty);
	QueuePush(pEmpty, res);

	return res;
}

void TestQStack() {
	QStack stack;
	QSInit(&stack);

	for (int i = 0; i < 10; i++) {
		QSPush(&stack, i);
		printf("压入了 %d, Top = %d\n", i, QSFront(&stack));
	}
	
	printf("----------\n");

	for (int i = 0; i < 9; i++) {
		QSPop(&stack);
		printf("Top = %d\n", QSFront(&stack));
	}
}



int main() {
	TestQStack();

	system("pause");
} 