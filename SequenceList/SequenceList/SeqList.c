#include "SeqList.h"

// �ӿڣ�������
// ��ʼ�� & ����
// ��ɾ�Ĳ�

// ��ʼ����������ƣ�
void SeqListInit(SeqList* ptr) {
	assert(ptr);
	ptr->size = 0;
}

// ����
void SeqListDestroy(SeqList* ptr) {
	assert(ptr);
	ptr->size = 0;
}

// ��
// β��
void SeqListPuchBack(SeqList* ptr, DataType data) {
	assert(ptr);

	// ������������ˣ�
	if (ptr->size >= MAX_SIZE) {
		printf("����\n");
		assert(0);
		return;
	}

	// ͨ�����
	ptr->array[ptr->size] = data;
	ptr->size += 1;
}

// ͷ��
void SeqListPushFront(SeqList* ptr, DataType data) {
	assert(ptr);

	// ������������ˣ�
	if (ptr->size >= MAX_SIZE) {
		printf("����\n");
		assert(0);
		return;
	}

	// ͨ�����
	for (int i = ptr->size; i > 0; i--)
		ptr->array[i] = ptr->array[i - 1];
	ptr->array[0] = data;
	ptr->size += 1;
}

// ����
void SeqListInsert(SeqList* ptr, DataType data, int index) {
	assert(ptr);

	// ������������ˣ�
	if (ptr->size >= MAX_SIZE) {
		printf("����\n");
		assert(0);
		return;
	}

	// ���������index���Ϸ���
	if (index < 0 || index > ptr->size) {
		printf("index���Ϸ�\n");
		assert(0);
		return;
	}

	// ͨ�����
	for (int i = ptr->size; i > index; i--) {
		ptr->array[i] = ptr->array[i - 1];
	}
	ptr->array[index] = data;
	ptr->size += 1;
}

// ɾ
// βɾ
void SeqListPopBack(SeqList* ptr) {
	assert(ptr);

	// ������������ˣ�
	if (ptr->size <= 0) {
		printf("����\n");
		assert(0);
		return;
	}

	// ͨ�����
	ptr->size -= 1;
}

// ͷɾ
void SeqListPopFront(SeqList* ptr) {
	assert(ptr);

	// ������������ˣ�
	if (ptr->size <= 0) {
		printf("����\n");
		assert(0);
		return;
	}

	// ͨ�����
	for (DataType i = 1; i < ptr->size; i++)
		ptr->array[i - 1] = ptr->array[i];
	ptr->size -= 1;
}

// ɾ���������±꣩
void SeqListDelete_1(SeqList* ptr, int index) {
	assert(ptr);

	// ������������ˣ�
	if (ptr->size <= 0) {
		printf("����\n");
		assert(0);
		return;
	}

	// ���������index���Ϸ���
	if (index < 0 || index >= ptr->size) {
		printf("index���Ϸ�\n");
		assert(0);
		return;
	}

	//ͨ�����
	for (int i = index; i < ptr->size - 1; i++) {
		ptr->array[i] = ptr->array[i + 1];
	}
	ptr->size -= 1;
}

// ɾ�����������ݣ�ֻɾ��һ�������ģ�
void SeqListDelete_2(SeqList* ptr, DataType data) {
	int index = SeqListFind(ptr, data);
	if (index == -1) {
		return;
	}

	SeqListDelete_1(ptr, index);
}

// ɾ�����������ݣ�ɾ��ȫ�����ϵģ�
void SeqListDeleteAll(SeqList* ptr, DataType data) {
	int i, j;
	for (i = 0, j = 0; j < ptr->size; j++) {
		if (ptr->array[j] != data)
			ptr->array[i++] = ptr->array[j];
	}
	ptr->size = i;
}

// ����
// �ҵ���һ�������ĸ������±꣬û�ҵ�����-1
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