#include "Queue.h"

// 1. ��������ʵ��һ��ջ

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
// ֻ���ǿն��������
// ����������ж��ǿյģ�����queue_1���
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

	// �����������ж�Ϊ��
	assert(!QueueEmpty(pNotEmpty));

	// �ӷǿն������ƶ�size-1��Ԫ�ص��ն���
	while (QueueSize(pNotEmpty) > 1) {
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}

	// pNotEmpty������ֻʣһ������
	QueuePop(pNotEmpty);
}

QDataType QSFront(QStack* pQS) {
	Queue* pEmpty = &(pQS->queue_2);
	Queue* pNotEmpty = &(pQS->queue_1);
	if (!QueueEmpty(pEmpty)) {
		pEmpty = &(pQS->queue_1);
		pNotEmpty = &(pQS->queue_2);
	}

	// �����������ж�Ϊ��
	assert(!QueueEmpty(pNotEmpty));

	// �ӷǿն������ƶ�size-1��Ԫ�ص��ն���
	while (QueueSize(pNotEmpty) > 1) {
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}

	// pNotEmpty������ֻʣһ������
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
		printf("ѹ���� %d, Top = %d\n", i, QSFront(&stack));
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