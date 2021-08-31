#ifndef _STACK_
#define _STACK_

#include <stdio.h>
#include <stdlib.h>
#include "../SingleLinkedList/SinglyLinkedList.h"

typedef struct _Stack
{
	LinkedList* array;
	int maxElementCount;
	int top;
} Stack;

Stack* createStack(int maxElementCount);
int IsEmpty(Stack* sp);
int StackLength(Stack *sp);
int IsFull(Stack *sp);
void push(Stack *sp, ListNode element);
int pop(Stack *sp);
void* peek(Stack *sp);
void displayStackElement(Stack *sp);
int checkBracketMatching(Stack *sp, char* expression);

#endif
