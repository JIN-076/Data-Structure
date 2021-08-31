#include "Maze.h"

void displayCoordinate(Stack *sp)
{
	printf("----------------------\n");
	for (int i = 0; i < StackLength(sp); i++) {
		printf("[ %d, %d ]\n",
		((Coordinate*)sp->array->pElement[i].data)->x,
		((Coordinate*)sp->array->pElement[i].data)->y);
	}
}

void displayMap(ArrayListArray *two_Board, int x, int y)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == x && j == y)
				printf("⭕️");
			else if (*(int*)two_Board->aList[i]->pElement[j].data == 100)
				printf("👣");
			else if (*(int*)two_Board->aList[i]->pElement[j].data == 1)
				printf("⬛️");
			else if (*(int*)two_Board->aList[i]->pElement[j].data == 2)
				printf("❌");
			else if (*(int*)two_Board->aList[i]->pElement[j].data == 0)
				printf("⬜️");
		}
		printf("\n");
	}
	printf("\n");
}
