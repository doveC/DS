#include "Stack.h"

// 1. 设有数据元素序列{a, b, c, d, e, f, g}，进栈操作和出栈操作可以任意进行
//    下面哪些数据元素序列可以得到
//    {d, e, c, f, b, g, a} y
//    {f, e, g, d, a, c, b} n
//    {e, f, d, g, b, c, a} n
//    {c, d, b, e, f, a, g} y

// 2. 括号匹配问题（笔记）
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
				printf("右括号多了\n");
				StackDestroy(&stack);
				return;
			}

			leftBracket = (char)StackTop(&stack);
			StackPop(&stack);

			if (leftBracket == '(' && ch != ')') {
				printf("不匹配\n");
				return;
			}

			if (leftBracket == '[' && ch != ']') {
				printf("不匹配\n");
				return;
			}

			if (leftBracket == '{' && ch != '}') {
				printf("不匹配\n");
				return;
			}
		default:
			break;
		}
	}

	if (!StackEmpty(&stack)) {
		printf("左括号多了\n");
		return;
	}

	printf("完美匹配！\n");
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

// 3. 逆波兰表达式 (笔记)
typedef enum {
	OPERAND,  // 操作数
	OPERATOR,  // 操作符
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
		switch (e.type) {  // 判断是操作数还是操作符
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