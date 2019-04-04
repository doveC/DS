#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// 链式队列

typedef int QDataType;

typedef struct QNode {
	QDataType data;
	struct QNode* next;
} QNode;

typedef struct Queue {
	QNode* front;
	QNode* rear;
} Queue;

// 初始化/销毁
void QueueInit(Queue* pQueue);

void QueueDestroy(Queue* pQueue);

// 建立一个新结点
static QNode* CreateQNode(QDataType);

// 插入（尾插）
void QueuePush(Queue* pQueue, QDataType data);

// 删除（头删）
void QueuePop(Queue* pQueue);

// 查看队首数据
QDataType QueueFront(Queue* pQueue);

// 是否为空
int QueueEmpty(const Queue* pQueue);

// 返回数据个数
int QueueSize(const Queue* pQueue);
