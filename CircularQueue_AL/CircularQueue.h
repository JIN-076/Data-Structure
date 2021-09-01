#ifndef CIRCULARQUEUE_
#define CIRCULARQUEUE_

#include "../ArrayList/ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayCircularQueue
{
	int front;
	int rear;
	ArrayList* array;
} CircularQueue;

CircularQueue* createCircularQueue(int maxElementCount);
int enqueue(CircularQueue* cq, ArrayListNode element);
ArrayListNode* dequeue(CircularQueue* cq);
ArrayListNode* peek(CircularQueue* cq);
void deleteCircularQueue(CircularQueue* cq);
int IsFull(CircularQueue* cq);
int IsEmpty(CircularQueue* cq);
void displayCircularQueue(CircularQueue* cq);

#endif
