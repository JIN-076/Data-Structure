#ifndef _MAZE
#define _MAZE

#include "../Stack_AL/Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int myMaze[8][8] = {
	{0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0}
};

static int DIRECTION_OFFSETS[4][2] = {
	{-1, 0},  // 좌
	{0, 1},  // 하
	{1, 0},  // 우
	{0, -1} // 상
};

typedef struct Coordinate
{
	int x;
	int y;
} Coordinate;

void displayCoordinate(Stack *sp);
void displayMap(ArrayListArray *two_Board, int x, int y);

#endif
