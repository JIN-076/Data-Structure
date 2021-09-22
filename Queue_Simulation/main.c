#include "Simulation.h"

int main()
{
	CircularQueue *cq = NULL;
	CircularQueue *log = NULL;
	ArrayListNode node;
	ArrayListNode node_log;
	int maxElementCount = 30;
	int minutes = 60;
	int service_time = 0;
	int service_customer;
	int total_customer = 0;
	int total_wait = 0;

	//const int max_len = 5;
	//char str[max_len + 1] = { 0, };

	cq = createCircularQueue(maxElementCount);
	log = createCircularQueue(maxElementCount);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++)
	{
		printf("현재 시각 = %d [남은 대기인원 : %d]\n", clock, getCount(cq));
		if ((rand() % 10) < 3)
		{
			//int len = get_random_number(4, max_len);
			//get_random_str(str, len);
			SimCustomer* customer = malloc(sizeof(struct SimCustomerType));
			customer->status = arrival;
			customer->id = total_customer++;
			customer->arrivalTime = clock;
			customer->serviceTime = rand() % 3 + 1;
			node.data = customer;
			enqueue(cq, node);
			//Queue_print(cq);
			printf("고객 %d님이 %d분에 들어옵니다. [업무 처리시간 : %d분]\n", customer->id, customer->arrivalTime, customer->serviceTime);
		}
		if (service_time > 0)
		{
			printf("현재 고객 %d의 업무 처리 중입니다.\n", service_customer);
			service_time--;
		}
		else
		{
			if (!IsEmpty(cq))
			{
				SimCustomer* customer_log = ((SimCustomer*)dequeue(cq)->data);
				customer_log->startTime = clock;
				SimCustomer	*tmp = malloc(sizeof(struct SimCustomerType));
				tmp->id = customer_log->id;
				tmp->arrivalTime = customer_log->arrivalTime;
				tmp->serviceTime = customer_log->serviceTime;
				tmp->endTime = customer_log->endTime;
				tmp->startTime = customer_log->startTime;
				node_log.data = tmp;
				enqueue(log, node_log);
				service_customer = customer_log->id;
				service_time = customer_log->serviceTime;
				printf("고객 %d님이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다\n",
					customer_log->id, clock, clock - customer_log->arrivalTime);
				total_wait += clock - customer_log->arrivalTime;
			}
		}
	}
	printf("전체 대기 시간 = %d분\n", total_wait);
	printf("대기 고객 %d명\n", getCount(cq));
	if (!IsEmpty(cq))
	{
		if (cq->front < cq->rear)
		{
			for (int i = cq->front + 1; i <= cq->rear; i++)
			{
				printf("[%d] %d분 도착, [%d분 대기] 작업시간 %d분\n",
				((SimCustomer*)cq->array->pElement[i].data)->id,
				((SimCustomer*)cq->array->pElement[i].data)->arrivalTime,
				minutes - ((SimCustomer*)cq->array->pElement[i].data)->arrivalTime,
				((SimCustomer*)cq->array->pElement[i].data)->serviceTime);
			}
		}
		else
		{
			for (int i = cq->front + 1; i < maxElementCount; i++)
			{
				printf("[%d] %d분 도착, [%d분 대기] 작업시간 %d분\n",
				((SimCustomer*)cq->array->pElement[i].data)->id,
				((SimCustomer*)cq->array->pElement[i].data)->arrivalTime,
				minutes - ((SimCustomer*)cq->array->pElement[i].data)->arrivalTime,
				((SimCustomer*)cq->array->pElement[i].data)->serviceTime);
			}
			for (int i = 0; i < cq->rear + 1; i++)
			{
				printf("[%d] %d분 도착, [%d분 대기] 작업시간 %d분\n",
				((SimCustomer*)cq->array->pElement[i].data)->id,
				((SimCustomer*)cq->array->pElement[i].data)->arrivalTime,
				minutes - ((SimCustomer*)cq->array->pElement[i].data)->arrivalTime,
				((SimCustomer*)cq->array->pElement[i].data)->serviceTime);
			}
		}
	}
	printf("Customer log\n");
	if (!IsEmpty(log))
	{
		for (int Idx = log->front + 1; Idx <= log->rear; Idx++)
		{
			printf("[%2d] %2d분 도착, [업무처리시간 : %d], [%2d분 대기] %2d ~ %2d분\n",
				((SimCustomer*)log->array->pElement[Idx].data)->id,
				((SimCustomer*)log->array->pElement[Idx].data)->arrivalTime,
				((SimCustomer*)log->array->pElement[Idx].data)->serviceTime,
				((SimCustomer*)log->array->pElement[Idx].data)->startTime - ((SimCustomer*)log->array->pElement[Idx].data)->arrivalTime,
				((SimCustomer*)log->array->pElement[Idx].data)->startTime,
				((SimCustomer*)log->array->pElement[Idx].data)->startTime + ((SimCustomer*)log->array->pElement[Idx].data)->serviceTime);
		}
	}
	return (0);
}
