#include "CircularQueue.h"

CircularQueue* createCircularQueue(int maxElementCount)
{
	CircularQueue *cq = malloc(sizeof(CircularQueue));
	ArrayList* pList = NULL;
	pList = createArrayList(maxElementCount);
	cq->array = pList;
	cq->front = pList->currentElementCount - 1;
	cq->rear = pList->currentElementCount - 1;
	return (cq);
}

int enqueue(CircularQueue* cq, ArrayListNode element)
{
	int flag = TRUE;
	if (cq != NULL)
	{
		if (!IsFull(cq))
		{
			cq->rear = (cq->rear + 1) % (cq->array->maxElementCount);
			cq->array->pElement[cq->rear] = element;
			cq->array->currentElementCount++;
			flag = TRUE;
		}
		else
			printf("Now, You can't enqueue the data in Queue. Queue is FULL!\n");
	}
	return (flag);
}

ArrayListNode* dequeue(CircularQueue* cq)
{
	ArrayListNode* List = NULL;
	if (cq != NULL)
	{
		if (!IsEmpty(cq))
		{
			List = (ArrayListNode*)malloc(sizeof(ArrayListNode));
			if (List != NULL)
			{
				cq->front = (cq->front + 1) % (cq->array->maxElementCount);
				List->data = getALElement(cq->array, cq->front)->data;
				cq->array->currentElementCount--;
			}
			else
				printf("Memory Allocation Failure\n");
		}
		else
			printf("Now, you can't dqeueue in data in Queue. Queue is EMPTY!\n");
	}
	return (List);
}

ArrayListNode* peek(CircularQueue* cq)
{
	ArrayListNode* List = NULL;
	if (cq != NULL)
	{
		if (!IsEmpty(cq))
		{
			List = (ArrayListNode*)malloc(sizeof(ArrayListNode));
			if (List != NULL)
				List->data = getALElement(cq->array, cq->front + 1)->data;
			else
				printf("Memory Allocation Failure\n");
		}
		else
			printf("Now, you can't peek in data. Queue is EMPTY!\n");
	}
	return (List);
}

void deleteCircularQueue(CircularQueue* cq)
{
	if (cq != NULL)
	{
		if (cq->array->pElement != NULL)
		{
			free(cq->array->pElement);
		}
		free(cq->array);
	}
}

int IsFull(CircularQueue* cq)
{
	int flag = FALSE;
	if (cq != NULL)
	{
		if (cq->array->currentElementCount == cq->array->maxElementCount)
			flag = TRUE;
	}
	return (flag);
}

int IsEmpty(CircularQueue* cq)
{
	int flag = FALSE;
	if (cq != NULL)
	{
		if (cq->array->currentElementCount == 0)
			flag = TRUE;
	}
	return (flag);
}

void displayCircularQueue(CircularQueue* cq)
{
	if (cq != NULL)
	{
		printf("[ Queue maxElementCount : %d\n", cq->array->maxElementCount);
		printf("[ Queue CurrentElementCount : %d\n", cq->array->currentElementCount);
		int Idx = 0;
		for (int i = 1; i < cq->array->currentElementCount + 1; i++)
		{
			Idx = (cq->front + i) % (cq->array->maxElementCount);
			printf("[ %d번째 원소 ] : %d\n", Idx, *(int*)cq->array->pElement[Idx].data);
		}
	}
}
