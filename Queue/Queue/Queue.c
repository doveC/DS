#include "Queue.h"

void QueueInit(Queue* pQueue) {
	pQueue->front = pQueue->rear = NULL;
}

void QueueDestroy(Queue* pQueue) {
	QNode *curr, *next;
	
	for (curr = pQueue->front; curr != NULL; curr = next) {
		next = curr->next;
		free(curr);
	}
	pQueue->front = pQueue->rear = NULL;
}

static QNode* CreateQNode(QDataType data) {
	QNode* newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void QueuePush(Queue* pQueue, QDataType data) {
	QNode* newNode = CreateQNode(data);

	if (pQueue->front == NULL) {  // ����ǿն���
		pQueue->front = newNode;
		pQueue->rear = newNode;
	}
	else {
		pQueue->rear->next = newNode;  // ���ǿն���
		pQueue->rear = newNode;
	}
}

void QueuePop(Queue* pQueue) {
	assert(pQueue->front);  // �����ǿն���

	QNode* ptr4free = pQueue->front;

	if (pQueue->front == pQueue->rear) {  // ���ֻ��һ��Ԫ�أ���βָ��ָ��NULL
		pQueue->rear = NULL;
	}
	pQueue->front = pQueue->front->next;  // ͷָ��ָ��ͷָ���next

	free(ptr4free);
}

QDataType QueueFront(Queue* pQueue) {
	assert(pQueue->front);  // �����ǿն���

	return pQueue->front->data;
}

int QueueEmpty(const Queue* pQueue) {
	return pQueue->front == NULL;
}

int QueueSize(const Queue* pQueue) {
	int size = 0;
	QNode* curr;
	for (curr = pQueue->front; curr != NULL; curr = curr->next)
		size++;

	return size;
}
