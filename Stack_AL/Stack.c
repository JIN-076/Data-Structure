#include "Stack.h"

Stack* createStack(int maxElementCount)
{
	Stack* sp = malloc(sizeof(Stack));
	ArrayList* pList = NULL;
	pList = createArrayList(maxElementCount);
	sp->array = pList;
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
	if (StackLength(sp) >= sp->array->maxElementCount)
		return (TRUE);
	return (FALSE);
}

void push(Stack *sp, ArrayListNode element)
{
	if (IsFull(sp))
		printf("You can't Push the element!\n");
	else
		addALElement(sp->array, (++(sp->top)), element);
}

int pop(Stack *sp)
{
	if (IsEmpty(sp))
		return (ERROR);
	return (removeALElement(sp->array, (sp->top)--));
}

void* peek(Stack *sp)
{
	if (IsEmpty(sp))
	{
		printf("Stack is Empty. You can't access the peek of Stack\n");
		return (0);
	}
	return (getALElement(sp->array, sp->top)->data);
}

void displayStackElement(Stack *sp)
{
	printf("---------------------\n");
	for (int i = 0; i < sp->array->currentElementCount; i++)
		printf("[ %d 번째 인덱스 ] : %c\n", i, *(char*)getALElement(sp->array, i)->data);
}

int checkBracketMatching(Stack *sp, char* expression)
{
	int result = TRUE;
	int i = 0;
	int count = 0;
	ArrayListNode symbol;
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
					ArrayListNode checkSymbol;
					checkSymbol.data = sp->array->pElement[sp->top].data;
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
					ArrayListNode checkSymbol;
					checkSymbol.data = sp->array->pElement[sp->top].data;
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
					ArrayListNode checkSymbol;
					checkSymbol.data = sp->array->pElement[sp->top].data;
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
