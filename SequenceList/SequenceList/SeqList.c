#include "SeqList.h"

// 接口（函数）
// 初始化 & 销毁
// 增删改查

// 初始化（函数设计）
void SeqListInit(SeqList* ptr) {
	assert(ptr);
	ptr->size = 0;
}

// 销毁
void SeqListDestroy(SeqList* ptr) {
	assert(ptr);
	ptr->size = 0;
}

// 增
// 尾插
void SeqListPuchBack(SeqList* ptr, DataType data) {
	assert(ptr);

	// 特殊情况（满了）
	if (ptr->size >= MAX_SIZE) {
		printf("满了\n");
		assert(0);
		return;
	}

	// 通常情况
	ptr->array[ptr->size] = data;
	ptr->size += 1;
}

// 头插
void SeqListPushFront(SeqList* ptr, DataType data) {
	assert(ptr);

	// 特殊情况（满了）
	if (ptr->size >= MAX_SIZE) {
		printf("满了\n");
		assert(0);
		return;
	}

	// 通常情况
	for (int i = ptr->size; i > 0; i--)
		ptr->array[i] = ptr->array[i - 1];
	ptr->array[0] = data;
	ptr->size += 1;
}

// 插入
void SeqListInsert(SeqList* ptr, DataType data, int index) {
	assert(ptr);

	// 特殊情况（满了）
	if (ptr->size >= MAX_SIZE) {
		printf("满了\n");
		assert(0);
		return;
	}

	// 特殊情况（index不合法）
	if (index < 0 || index > ptr->size) {
		printf("index不合法\n");
		assert(0);
		return;
	}

	// 通常情况
	for (int i = ptr->size; i > index; i--) {
		ptr->array[i] = ptr->array[i - 1];
	}
	ptr->array[index] = data;
	ptr->size += 1;
}

// 删
// 尾删
void SeqListPopBack(SeqList* ptr) {
	assert(ptr);

	// 特殊情况（空了）
	if (ptr->size <= 0) {
		printf("空了\n");
		assert(0);
		return;
	}

	// 通常情况
	ptr->size -= 1;
}

// 头删
void SeqListPopFront(SeqList* ptr) {
	assert(ptr);

	// 特殊情况（空了）
	if (ptr->size <= 0) {
		printf("空了\n");
		assert(0);
		return;
	}

	// 通常情况
	for (DataType i = 1; i < ptr->size; i++)
		ptr->array[i - 1] = ptr->array[i];
	ptr->size -= 1;
}

// 删除（根据下标）
void SeqListDelete_1(SeqList* ptr, int index) {
	assert(ptr);

	// 特殊情况（空了）
	if (ptr->size <= 0) {
		printf("空了\n");
		assert(0);
		return;
	}

	// 特殊情况（index不合法）
	if (index < 0 || index >= ptr->size) {
		printf("index不合法\n");
		assert(0);
		return;
	}

	//通常情况
	for (int i = index; i < ptr->size - 1; i++) {
		ptr->array[i] = ptr->array[i + 1];
	}
	ptr->size -= 1;
}

// 删除（根据数据，只删第一个遇到的）
void SeqListDelete_2(SeqList* ptr, DataType data) {
	int index = SeqListFind(ptr, data);
	if (index == -1) {
		return;
	}

	SeqListDelete_1(ptr, index);
}

// 删除（根据数据，删除全部符合的）
void SeqListDeleteAll(SeqList* ptr, DataType data) {
	int i, j;
	for (i = 0, j = 0; j < ptr->size; j++) {
		if (ptr->array[j] != data)
			ptr->array[i++] = ptr->array[j];
	}
	ptr->size = i;
}

// 查找
// 找到第一个遇到的该数的下标，没找到返回-1
int SeqListFind(SeqList* ptr, DataType data) {
	for (DataType i = 0; i < ptr->size; i++) {
		if (data == ptr->array[i])
			return i;
	}
	return -1;
}

void SeqListPrint(const SeqList* ptr) {
	assert(ptr);

	for (DataType i = 0; i < ptr->size; i++)
		printf("%d -> ", ptr->array[i]);
	printf("\n");
}

void Test() {
	SeqList seqList;
	SeqListInit(&seqList);

	SeqListInsert(&seqList, 1, 0);
	SeqListInsert(&seqList, 2, 0);
	SeqListInsert(&seqList, 3, 0);
	SeqListInsert(&seqList, 4, 0);
	SeqListInsert(&seqList, 3, 0);

	SeqListPrint(&seqList);

	SeqListDeleteAll(&seqList, 3);

	SeqListPrint(&seqList);
}