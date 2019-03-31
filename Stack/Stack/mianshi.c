#include "Stack.h"

// 1. ��������Ԫ������{a, b, c, d, e, f, g}����ջ�����ͳ�ջ���������������
//    ������Щ����Ԫ�����п��Եõ�
//    {d, e, c, f, b, g, a} y
//    {f, e, g, d, a, c, b} n
//    {e, f, d, g, b, c, a} n
//    {c, d, b, e, f, a, g} y

// 2. ����ƥ�����⣨�ʼǣ�
void BracketMatch(const char* sequence, int size) {
	Stack stack;
	StackInit(&stack);
	char ch;
	char leftBracket;

	for (int i = 0; i < size; i++) {
		ch = sequence[i];

		switch (ch) {
		case '(':
		case '[':
		case '{':
			StackPush(&stack, (StackDataType)ch);
			break;
		case ')':
		case ']':
		case '}':
			if (StackEmpty(&stack)) {
				printf("�����Ŷ���\n");
				StackDestroy(&stack);
				return;
			}

			leftBracket = (char)StackTop(&stack);
			StackPop(&stack);

			if (leftBracket == '(' && ch != ')') {
				printf("��ƥ��\n");
				return;
			}

			if (leftBracket == '[' && ch != ']') {
				printf("��ƥ��\n");
				return;
			}

			if (leftBracket == '{' && ch != '}') {
				printf("��ƥ��\n");
				return;
			}
		default:
			break;
		}
	}

	if (!StackEmpty(&stack)) {
		printf("�����Ŷ���\n");
		return;
	}

	printf("����ƥ�䣡\n");
}

void TestBracket() {
	const char* seq[] = {
		"(())abc{[(])}",
		"(()))abc{[]}",
		"(()()abc{[]}",
		"(())abc{[]()}",
	};

	for (int i = 0; i < 4; i++) {
		BracketMatch(seq[i], strlen(seq[i]));
	}
}

// 3. �沨�����ʽ (�ʼ�)
typedef enum {
	OPERAND,  // ������
	OPERATOR,  // ������
} Type;

typedef enum {
	ADD, SUB, MUL, DIV, NONE,
} Operator;

typedef struct {
	Type type;
	int operand;
	Operator operator;
} Element;

int caculate(Operator operator, int a, int b) {
	int result;

	switch (operator) {
	case ADD:
		result = a + b;
		break;
	case SUB:
		result = a - b;
		break;
	case MUL:
		result = a * b;
		break;
	case DIV:
		result = a / b;
		break;
	default:
		assert(0);
	}
}

int ReversePolishNotion(Element expression[], int size) {
	Stack stack;
	int op1, op2;
	int result;
	StackInit(&stack);

	for (int i = 0; i < size; i++) {
		Element e = expression[i];
		switch (e.type) {  // �ж��ǲ��������ǲ�����
		case OPERAND:
			StackPush(&stack, e.operand);
			break;
		case OPERATOR:
			op1 = StackTop(&stack); StackPop(&stack);
			op2 = StackTop(&stack); StackPop(&stack);
			result = caculate(e.operator, op2, op1);
			StackPush(&stack, result);
			break;
		default:
			assert(0);
		}
	}

	assert(StackSize(&stack) == 1);
	result = StackTop(&stack);

	return result;
}

void TestRPN() {
	// (1 + 2) * 4 / 3
	// 1 2 + 4 * 3 /
	Element expression[] = {
		{OPERAND, 1, NONE},
		{OPERAND, 2, NONE},
		{OPERATOR, -1, ADD},
		{OPERAND, 4, NONE},
		{OPERATOR, -1, MUL},
		{OPERAND, 3, NONE},
		{OPERATOR, -1, DIV},
	};

	int result = ReversePolishNotion(expression, 7);

	printf("result: %d\n", result);
}

//int main() {
//	// TestBracket();
//	TestRPN();
//
//	system("pause");
//	return 0;
//}