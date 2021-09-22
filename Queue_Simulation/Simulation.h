#ifndef _SIMULATION_
#define _SIMULATION_

#include "../CircularQueue_AL/CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum SimStatusType {
	arrival,
	start,
	end
} SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int id;
	int arrivalTime; 	// 도착 시각
	int serviceTime; 	// 서비스 시간
	int startTime; 		// 시작 시각
	int endTime; 		// 종료 시각 : 시작 시각 + 서비스 시간
} SimCustomer;

void error(char *message);
void Queue_print(CircularQueue *cq);
int getCount(CircularQueue* cq);
int get_random_number(int from, int to);
void get_random_str(char* data, int len);
void display(CircularQueue* cq);
void printCustomer(SimCustomer* customer);

#endif
