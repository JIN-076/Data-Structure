#ifndef _DEQUE_
#define _DEQUE_

#include "../DoubleLinkedList/DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Deque
{
	ListNode* head;
	ListNode* tail;
} Deque;

Deque* createDeque(Deque *dq);
int IsEmpty(Deque* dq);
void* pushFront(Deque* dq, ListNode element);
void* pushBack(Deque* dq, ListNode element);
void* popFront(Deque* dq);
void* popBack(Deque* dq);
void* getFront(Deque* dq);
void* getBack(Deque* dq);
void displayDeque(Deque *dq);

#endif
