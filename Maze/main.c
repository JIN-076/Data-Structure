#include "Maze.h"

int main()
{
	Stack* stack = NULL;
	ArrayListNode node;
	int maxElementCount = 30;
	int visited = 100;
	int Impossible = 2;

	ArrayListArray* two_Board;
	two_Board = addAList(maxElementCount);

	for (int i = 0; i < maxElementCount; i++)
		two_Board->aList[i] = createArrayList(maxElementCount);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			node.data = &myMaze[i][j];
			addALElement(two_Board->aList[i], j, node);
		}
	}

	stack = createStack(maxElementCount);

	Coordinate *start = malloc(sizeof(struct Coordinate));
	start->x = 0;
	start->y = 0;

	two_Board->aList[start->x]->pElement[start->y].data = &visited;

	Coordinate *next = malloc(sizeof(struct Coordinate));
	next->x = 0;
	next->y = 0;

	displayMap(two_Board, start->x, start->y);
	usleep(500000);

	while (start->x != 7 && start->y != 7)
	{
		//printf("%d,%d\n", start->x, start->y);

		int dir;
		int flag = FALSE;
		for (dir = 0; dir < 4; dir++)
		{
			next->x = start->x + DIRECTION_OFFSETS[dir][0];
			next->y = start->y + DIRECTION_OFFSETS[dir][1];

			if (next->x < 0 || next->x > 7 || next->y < 0 || next->y > 7)
				continue;
			if (*(int*)two_Board->aList[next->x]->pElement[next->y].data == 100)
				continue;
			if (*(int*)two_Board->aList[next->x]->pElement[next->y].data == 1)
				continue;
			if (*(int*)two_Board->aList[next->x]->pElement[next->y].data == 2)
				continue;
			if (*(int*)two_Board->aList[next->x]->pElement[next->y].data == 0)
			{
				Coordinate *tmp = malloc(sizeof(struct Coordinate));

				tmp->x = next->x;
				tmp->y = next->y;

				start = tmp;
				dir = 0;
				node.data = tmp;
				push(stack, node);

				two_Board->aList[tmp->x]->pElement[tmp->y].data = &visited;

				displayMap(two_Board, start->x, start->y);

				//displayCoordinate(stack);

				flag = TRUE;
				usleep(500000);
			}
		}
		if (flag == FALSE)
		{
			two_Board->aList[start->x]->pElement[start->y].data = &Impossible;
			pop(stack);
			start->x = ((Coordinate*)peek(stack))->x;
			start->y = ((Coordinate*)peek(stack))->y;
			displayMap(two_Board, start->x, start->y);
			usleep(500000);
		}
	}
}
