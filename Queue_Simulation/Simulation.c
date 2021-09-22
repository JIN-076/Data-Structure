#include "Simulation.h"

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void Queue_print(CircularQueue *cq)
{
	printf("Circular Queue (front = %d, rear = %d) =  ",  cq->front,  cq->rear);
	if (!IsEmpty(cq))
	{
		int Idx = cq->front;
		do {
			Idx = (Idx + 1) % (cq->array->maxElementCount);
			printf("%u | ", ((SimCustomer*)cq->array->pElement[Idx].data)->status);
			printf("%d | ", ((SimCustomer*)cq->array->pElement[Idx].data)->id);
			printf("%d | ", ((SimCustomer*)cq->array->pElement[Idx].data)->arrivalTime);
			printf("%d | ", ((SimCustomer*)cq->array->pElement[Idx].data)->serviceTime);
			printf("%d | ", ((SimCustomer*)cq->array->pElement[Idx].data)->startTime);
			if (Idx == cq->rear)
				break;
		} while (Idx != cq->front);
	}
	printf("\n");
}

int getCount(CircularQueue* cq)
{
	if (cq->front <= cq->rear)
		return (cq->rear - cq->front);
	else
		return (cq->rear + 1) + (cq->array->maxElementCount - 1 - cq->front);
}

int get_random_number(int from, int to)
{
	return (rand() % (to - from + 1) + from);
}

void get_random_str(char* data, int len)
{
	for (int i = 0; i < len; i++)
		data[i] = get_random_number(0, 25) + 'a';
	data[len] = 0;
}

void display(CircularQueue* cq)
{
	if (cq != NULL)
	{
		printf("[ Queue maxElementCount : %d\n", cq->array->maxElementCount);
		printf("[ Queue CurrentElementCount : %d\n", cq->array->currentElementCount);
		int Idx = 0;
		for (int i = 1; i < cq->array->currentElementCount + 1; i++)
		{
			Idx = (cq->front + i) % (cq->array->maxElementCount);
			printf("[ %d번째 원소 ] : %d\n", Idx, ((SimCustomer*)cq->array->pElement[Idx].data)->id);
			printf("[ %d번째 원소 ] : %d\n", Idx, ((SimCustomer*)cq->array->pElement[Idx].data)->arrivalTime);
			printf("[ %d번째 원소 ] : %d\n", Idx, ((SimCustomer*)cq->array->pElement[Idx].data)->startTime);
			printf("[ %d번째 원소 ] : %d\n", Idx, ((SimCustomer*)cq->array->pElement[Idx].data)->serviceTime);
			printf("[ %d번째 원소 ] : %d\n", Idx, ((SimCustomer*)cq->array->pElement[Idx].data)->endTime);
			printf("----------------------------------------\n");
		}
	}
}

void printCustomer(SimCustomer* customer)
{
	printf("-----------------------------\n");
	printf("%d\n", customer->id);
	printf("%d\n", customer->arrivalTime);
	printf("%d\n", customer->serviceTime);
}
