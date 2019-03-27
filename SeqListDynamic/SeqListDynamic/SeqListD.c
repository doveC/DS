#include "SeqListD.h"

void SeqListDInit(SeqListD *ptr) {
	ptr->capacity = INIT_CAPACIT;

	ptr->arr = (DataType *)malloc(sizeof(DataType) * ptr->capacity);
	assert(ptr->arr);

	ptr->size = 0;
}

void SeqListDDestroy(SeqListD* ptr) {
	free(ptr->arr);

	ptr->capacity = 0;
	ptr->arr = NULL;
	ptr->size = 0;
}

static void ExpandIfRequired(SeqListD* ptr) {
	if (ptr->size < ptr->capacity) {
		// û��
		return;
	}

	ptr->capacity *= 2;

	// �����¿ռ�
	DataType* newArr = (DataType *)malloc(sizeof(DataType) * ptr->capacity);

	// ���ݰ���
	for (int i = 0; i < ptr->size; i++) {
		newArr[i] = ptr->arr[i];
	}

	// �����¿ռ䣬�ͷ��Ͽռ�
	free(ptr->arr);
	ptr->arr = newArr;
}

void SeqListDPushBack(SeqListD* ptr, DataType data) {
	// ��̬������ˣ�����������
	// ��̬�������ݻ���

	ExpandIfRequired(ptr);

	ptr->arr[ptr->size] = data;
	ptr->size++;
}

void SeqListDPushFront(SeqListD* ptr, DataType data) {
	assert(ptr);

	ExpandIfRequired(ptr);

	for (int i = ptr->size; i > 0; i--) {
		ptr->arr[i] = ptr->arr[i - 1];
	}
	ptr->arr[0] = data;
	ptr->size++;
}

void SeqListDInsert(SeqListD* ptr, DataType data, int index) {
	assert(ptr);

	ExpandIfRequired(ptr);

	for (int i = ptr->size; i > index; --i) {
		ptr->arr[i] = ptr->arr[i - 1];
	}
	ptr->arr[index] = data;
	ptr->size++;
}

void SeqListPopFront(SeqListD* ptr) {
	assert(ptr);

	for (int i = 0; i < ptr->size - 1; i++) {
		ptr->arr[i] = ptr->arr[i + 1];
	}
	ptr->size--;
}

void SeqListDPopBack(SeqListD* ptr) {
	assert(ptr);

	ptr->size--;
}

void SeqListDDeleteAll(SeqListD* ptr, DataType data) {
	assert(ptr);

	int i, j;

	for (i = 0, j = 0; i < ptr->size; i++) {
		if (ptr->arr[i] != data) {
			ptr->arr[j++] = ptr->arr[i];
		}
	}
	ptr->size = j;
}

void Test() {
	SeqListD seqListD;
	SeqListDInit(&seqListD);

	SeqListDPushBack(&seqListD, 1);
	SeqListDPushBack(&seqListD, 2);
	SeqListDPushBack(&seqListD, 3);
	SeqListDPushBack(&seqListD, 4);
	SeqListDPushBack(&seqListD, 5);
}