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
	pQueue->front = NULL;
	pQueue->rear = NULL;
}

static QNode* QCreateQNode(QDataType data) {
	QNode* node = (QNode *)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;

	return node;
}

// Î²²å
void QueuePush(Queue* pQueue, QDataType data) {
	QNode* node = QCreateQNode(data);

	if (pQueue->front == NULL) {
		pQueue->front = node;
		pQueue->rear = node;
	}
	else {
		pQueue->rear->next = node;
		pQueue->rear = node;
	}
}

// Í·É¾
void QueuePop(Queue* pQueue) {
	assert(pQueue);

	QNode* ptr4free = pQueue->front;

	if (pQueue->front == pQueue->rear) {
		pQueue->front = pQueue->rear = NULL;
	}
	else {
		pQueue->front = pQueue->front->next;
	}

	free(ptr4free);
}

QDataType QueueFront(Queue* pQueue) {
	assert(pQueue);

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
