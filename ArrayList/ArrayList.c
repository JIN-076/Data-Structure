#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList* List = NULL;

	if (maxElementCount > 0)
	{
		List = (ArrayList*)malloc(sizeof(ArrayList));
		List->maxElementCount = maxElementCount;
		List->currentElementCount = 0;
		List->pElement = NULL;
	}
	else
	{
		printf("Error Generating! Please Check maxElementCount\n");
		List->pElement = NULL;
	}
	List->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);
	return List;
}

ArrayListArray *addAList(int maxElementCount)
{
	ArrayListArray *arList = NULL;

	if (maxElementCount > 0)
	{
		arList = (ArrayListArray*)malloc(sizeof(ArrayListArray));
		arList->maxElementCount = maxElementCount;
		arList->currentElementCount = 0;
		arList->aList = NULL;
	}
	else
	{
		printf("Error Generating! Please Check maxElementCount\n");
		arList->aList = NULL;
	}
	arList->aList = (ArrayList**)malloc(sizeof(ArrayList*) * maxElementCount);
	return arList;
}

void deleteArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		free(pList->pElement);
		free(pList);
	}
}

int isArrayListFull(ArrayList* pList)
{
	int flag = FALSE;
	if (pList != NULL)
	{
		if (pList->maxElementCount == pList->currentElementCount)
			flag = TRUE;
	}
	return flag;
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int flag = FALSE;
	if (pList != NULL)
	{
		if (isArrayListFull(pList) != TRUE)
		{
			if (position >= 0 && position <= pList->currentElementCount)
			{
				for (int i = pList->currentElementCount - 1; i >= position; i--)
				{
					pList->pElement[i + 1] = pList->pElement[i];
				}
				pList->pElement[position].data = (element.data);
				pList->currentElementCount++;
				flag = TRUE;
			}
		}
		else
			printf("You Can't add Element. Now position is Out of Range\n");
	}
	else
		printf("You Can't add Element. Now There's no memory\n");
	return flag;
}

int removeALElement(ArrayList* pList, int position)
{
	int flag = FALSE;
	if (pList != NULL)
	{
		if (position >= 0 && position < pList->currentElementCount)
		{
			for (int i = position; i < pList->currentElementCount - 1; i++)
			{
				pList->pElement[i] = pList->pElement[i + 1];
			}
			pList->currentElementCount--;
			flag = TRUE;
		}
		else
			printf("You Can't remove Element. Now position is Out of Range\n");
	}
	return flag;
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	ArrayListNode *List = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position < pList->currentElementCount)
		{
			List = &(pList->pElement[position]);
		}
		else
			printf("You can't get Element. Now position is Out of Range\n");
	}
	return List;
}

void displayArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		printf("maxElementCount : %d\n", pList->maxElementCount);
		printf("currentElementCount : %d\n", pList->currentElementCount);
		printf(" [ ");
		for (int i = 0; i < pList->currentElementCount; i++)
		{
			printf("%d ", *(int*)(pList->pElement[i]).data);
		}
		printf("]\n");
	}
	else
		printf("Now ArrayList is NULL\n");
}

void clearArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		for (int i = 0; i < pList->currentElementCount; i++)
			*(int*)pList->pElement[i].data = 0;
	}
	else
		printf("You can't clear ArrayList!\n");
}

int getArrayListLength(ArrayList* pList)
{
	int Length = 0;
	if (pList != NULL)
		Length = pList->currentElementCount;
	return Length;
}
