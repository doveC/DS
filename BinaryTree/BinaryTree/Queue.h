#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "BTree.h"

// ��ʽ����

typedef struct BTreeNode * QDataType;

typedef struct QNode {
	QDataType data;
	struct QNode* next;
} QNode;

typedef struct Queue {
	QNode* front;
	QNode* rear;
} Queue;

// ��ʼ��/����
void QueueInit(Queue* pQueue);

void QueueDestroy(Queue* pQueue);

// ����һ���½��
static QNode* QCreateQNode(QDataType data);

// ���루β�壩
void QueuePush(Queue* pQueue, QDataType data);

// ɾ����ͷɾ��
void QueuePop(Queue* pQueue);

// �鿴��������
QDataType QueueFront(Queue* pQueue);

// �Ƿ�Ϊ��
int QueueEmpty(const Queue* pQueue);

// �������ݸ���
int QueueSize(const Queue* pQueue);
