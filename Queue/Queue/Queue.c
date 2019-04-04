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

	if (pQueue->front == NULL) {  // 如果是空队列
		pQueue->front = newNode;
		pQueue->rear = newNode;
	}
	else {
		pQueue->rear->next = newNode;  // 不是空队列
		pQueue->rear = newNode;
	}
}

void QueuePop(Queue* pQueue) {
	assert(pQueue->front);  // 不能是空队列

	QNode* ptr4free = pQueue->front;

	if (pQueue->front == pQueue->rear) {  // 如果只有一个元素，让尾指针指向NULL
		pQueue->rear = NULL;
	}
	pQueue->front = pQueue->front->next;  // 头指针指向头指针的next

	free(ptr4free);
}

QDataType QueueFront(Queue* pQueue) {
	assert(pQueue->front);  // 不能是空队列

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
