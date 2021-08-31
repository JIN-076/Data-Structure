#include "Stack.h"

int main()
{
	Stack *stack = NULL;
	ArrayListNode node;
	int maxElementCount = 6;

	stack = createStack(maxElementCount);

	printf("Now, Stack is Full? : %d\n", IsFull(stack));

	char a = 'A';
	node.data = &a;
	push(stack, node);

	printf("[ peek index : %c ]\n", *(char*)peek(stack));

	char b = 'B';
	node.data = &b;
	push(stack, node);

	printf("[ peek index : %c ]\n", *(char*)peek(stack));

	char c = 'C';
	node.data = &c;
	push(stack, node);

	printf("[ peek index : %c ]\n", *(char*)peek(stack));

	char d = 'D';
	node.data = &d;
	push(stack, node);

	char e = 'E';
	node.data = &e;
	push(stack, node);

	char f = 'F';
	node.data = &f;
	push(stack, node);

	printf("Now, Stack is Full? : %d\n", IsFull(stack));

	char g = 'G';
	node.data = &g;
	push(stack, node);

	printf("[ peek index : %c ]\n", *(char*)peek(stack));

	displayStackElement(stack);

	pop(stack);

	printf("[ peek index : %c ]\n", *(char*)peek(stack));

	displayStackElement(stack);

	//char* expression = "((A*B)/C)-{(D+E)&&(F-G)}";
	//char* expression = "((A*B)/C-{(D+E)&&(F-G))}";
	//char* expression = "{(A+B)*C}";
	//char* expression = "(())())";
	//char* expression = "(((()())()";
	//char* expression = "(()())((()))";
	//char* expression = "((()()(()))(((())))()";
	//char* expression = "()()()()(()()())()";
	//char* expression = "(()((())()(";
	//char* expression = "((";
	//char* expression = "))";
	//char* expression = "())(()";

	//printf("%d\n", checkBracketMatching(stack, expression));
	//displayStackElement(stack);
}
