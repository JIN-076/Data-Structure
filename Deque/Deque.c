#include "Deque.h"

Deque* createDeque(Deque *dq)
{
	dq->head = NULL;
	dq->head = NULL;
	return (dq);
}

int IsEmpty(Deque* dq)
{
	if (dq->head == NULL)
		return (TRUE);
	else
		return (FALSE);
}

void* pushFront(Deque* dq, ListNode element)
{
	ListNode* pNode = (ListNode*)malloc(sizeof(ListNode));
	pNode->data = element.data;
	pNode->pRLink = dq->head;

	if (IsEmpty(dq))
		dq->tail = pNode;
	else
		dq->head->pLLink = pNode;
	pNode->pLLink = NULL;
	dq->head = pNode;
	return (pNode);
}

void* pushBack(Deque* dq, ListNode element)
{
	ListNode* pNode = (ListNode*)malloc(sizeof(ListNode));
	pNode->data = element.data;
	pNode->pLLink = dq->tail;

	if (IsEmpty(dq))
		dq->head = pNode;
	else
		dq->tail->pRLink = pNode;
	pNode->pRLink = NULL;
	dq->tail = pNode;
	return (pNode);
}

void* popFront(Deque* dq)
{
	ListNode* pNode = dq->head;
	ListNode node;
	if (IsEmpty(dq))
	{
		printf("Memory Allocation Failure\n");
		return (0);
	}
	node.data = dq->head->data;

	dq->head = dq->head->pRLink;
	free(pNode);

	if (dq->head == NULL)
		dq->tail = NULL;
	else
		dq->head->pLLink = NULL;
	return (node.data);
}

void* popBack(Deque* dq)
{
	ListNode* pNode = dq->tail;
	ListNode node;
	if (IsEmpty(dq))
	{
		printf("Memory Allocation Failure\n");
		return (0);
	}
	node.data = dq->tail->data;

	dq->tail = dq->tail->pLLink;
	free(pNode);

	if (dq->tail == NULL)
		dq->head = NULL;
	else
		dq->tail->pRLink = NULL;
	return (node.data);
}

void* getFront(Deque* dq)
{
	if (IsEmpty(dq))
	{
		printf("Deque is Empty");
		return (0);
	}
	return (dq->head->data);
}

void* getBack(Deque* dq)
{
	if (IsEmpty(dq))
	{
		printf("Deque is Empty");
		return (0);
	}
	return (dq->tail->data);
}

void displayDeque(Deque *dq)
{
	int cnt = 0;
	while (dq->head != NULL)
	{
		printf("[ %d번째 인덱스 ] : %d\n", cnt, *(int*)getFront(dq));
		cnt++;
		dq->head = dq->head->pRLink;
	}
}
