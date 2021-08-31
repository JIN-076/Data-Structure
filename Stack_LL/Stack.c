#include "Stack.h"

Stack* createStack(int maxElementCount)
{
	Stack *sp = malloc(sizeof(Stack));
	LinkedList* pList = NULL;
	pList = createLinkedList();
	sp->array = pList;
	sp->maxElementCount = maxElementCount;
	sp->top = pList->currentElementCount - 1;
	return (sp);
}

int IsEmpty(Stack* sp)
{
	if (sp->top == -1)
		return (TRUE);
	return (FALSE);
}

int StackLength(Stack *sp)
{
	return (sp->top + 1);
}

int IsFull(Stack *sp)
{
	if (StackLength(sp) >= sp->maxElementCount)
		return (TRUE);
	return (FALSE);
}

void push(Stack *sp, ListNode element)
{
	if (IsFull(sp))
		printf("You Can't push the elment. Now, Stack is Full\n");
	else
		addLLElement(sp->array, (++(sp->top)), element);
}

int pop(Stack *sp)
{
	if (IsEmpty(sp))
		return (ERROR);
	return (removeLLElement(sp->array, (sp->top)--));
}

void* peek(Stack *sp)
{
	if (IsEmpty(sp))
	{
		printf("Stack is Empty. You can't access the peek of Stack\n");
		return (0);
	}
	return (getLLElement(sp->array, sp->top)->data);
}

void displayStackElement(Stack *sp)
{
	printf("---------------------\n");
	for (int i = 0; i < sp->array->currentElementCount; i++)
		printf("[ %d 번째 인덱스 ] : %c\n", i, *(char*)getLLElement(sp->array, i)->data);
}

int checkBracketMatching(Stack *sp, char* expression)
{
	int result = TRUE;
	int i = 0;
	int count = 0;
	ListNode symbol;
	while (expression[i] != '\0' && result != FALSE)
	{
		symbol.data = &(expression[i]);
		switch(*(char*)symbol.data)
		{
			case '(': case '[': case '{':
				printf("%c is pushed stack\n", *(char*)symbol.data);
				push(sp, symbol);
				break;
			case ')':
				if (IsEmpty(sp))
					result = FALSE;
				else
				{
					ListNode checkSymbol;
					checkSymbol.data = getLLElement(sp->array, sp->top)->data;
					if (*(char*)checkSymbol.data != '(')
						result = FALSE;
					else
					{
						printf("%c is poped stack\n", *(char*)checkSymbol.data);
						pop(sp);
					}
				}
				break;
			case ']':
				if (IsEmpty(sp))
					result = FALSE;
				else
				{
					ListNode checkSymbol;
					checkSymbol.data = getLLElement(sp->array, sp->top)->data;
					if (*(char*)checkSymbol.data != '[')
						result = FALSE;
					else
					{
						printf("%c is poped stack\n", *(char*)checkSymbol.data);
						pop(sp);
					}
				}
				break;
			case '}':
				if (IsEmpty(sp))
					result = FALSE;
				else
				{
					ListNode checkSymbol;
					checkSymbol.data = getLLElement(sp->array, sp->top)->data;
					if (*(char*)checkSymbol.data != '{')
						result = FALSE;
					else
					{
						printf("%c is poped stack\n", *(char*)checkSymbol.data);
						pop(sp);
					}
				}
				break;
		}
		i++;
	}
	if (!IsEmpty(sp))
		result = FALSE;
	return (result);
}
