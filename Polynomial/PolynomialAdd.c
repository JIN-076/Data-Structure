#include "PolynomialAdd.h"

PolyList	*createPolyList(void)
{
	PolyList	*newPolyList;

	newPolyList = (PolyList *)malloc(sizeof(PolyList));
	if (!newPolyList)
		return (NULL);
	memset(newPolyList, 0, sizeof(PolyList));
	return (newPolyList);
}

int	insertPolyNode(PolyList *pList, PolyNode element)
{
	PolyNode	*pPrevNode;
	PolyNode	*pCurrentNode;
	PolyNode	*pNewNode;

	if (!pList)
	{
		printf("PolyList Non Existing!");
		return (ERROR);
	}
	pPrevNode = &(pList->headerNode);
	pCurrentNode = pPrevNode->pNext;

	while (pCurrentNode && (element.degree < pCurrentNode->degree))
	{
		pPrevNode = pPrevNode->pNext;
		pCurrentNode = pCurrentNode->pNext;
	}

	if (!pCurrentNode || (element.degree > pCurrentNode->degree))
	{
		pNewNode = (PolyNode *)malloc(sizeof(PolyNode));
		if(!pNewNode)
			return (ERROR);
		*pNewNode = element;
		pNewNode->pNext = pCurrentNode;
		pPrevNode->pNext = pNewNode;
		pList->currentElementCount++;
	}
	else if (element.degree == pCurrentNode->degree)
	{
		pCurrentNode->coef += element.coef;
		if (pCurrentNode->coef == 0)
		{
			pPrevNode->pNext = pCurrentNode->pNext;
			free(pCurrentNode);
			pCurrentNode = NULL;
			pList->currentElementCount--;
		}
	}
	return (TRUE);
}

PolyList	*addPolyList(PolyList *pList1, PolyList *pList2)
{
	PolyList	*retPolyList;
	PolyNode	*pCurrentNode;

	if (!pList1 || !pList2)
	{
		printf("PolyList Non Existing!");
		return (NULL);
	}
	// 두 다항식 중 하나라도 항이 존재하지 않는 경우
	if (!(pList1->headerNode.pNext))
	{
		printf("Polynomial Non Existing!");
		return (NULL);
	}

	retPolyList = (PolyList *)malloc(sizeof(PolyList));
	if (!retPolyList)
		return (NULL);
	pCurrentNode = pList1->headerNode.pNext;
	while (pCurrentNode)
	{
		insertPolyNode(retPolyList, *pCurrentNode);
		pCurrentNode = pCurrentNode->pNext;
	}
	pCurrentNode = pList2->headerNode.pNext;
	while (pCurrentNode)
	{
		insertPolyNode(retPolyList, *pCurrentNode);
		pCurrentNode = pCurrentNode->pNext;
	}
	return (retPolyList);
}

void	displayPolyList(PolyList *pList)
{
	PolyNode	*pCurrentNode;

	if (!pList)
	{
		printf("PolyList Non Existing!");
		return ;
	}
	printf("현재 저장한 노드 수 : %d\n", pList->currentElementCount);
	pCurrentNode = pList->headerNode.pNext;
	while (pCurrentNode != NULL)
	{
		if (pCurrentNode->degree)
			printf("(%d)x^%d", pCurrentNode->coef, pCurrentNode->degree);
		else
			printf("(%d)", pCurrentNode->coef);
		pCurrentNode = pCurrentNode->pNext;
		if (pCurrentNode)
			printf(" + ");
	}
	printf("\n");
}

void	deletePolyList(PolyList *pList)
{
	PolyNode	*pCurrentNode;

	if (!pList)
	{
		printf("PolyList Non Existing!");
		return ;
	}
	pCurrentNode = pList->headerNode.pNext;
	while (pCurrentNode != NULL)
	{
		pList->headerNode.pNext = pCurrentNode->pNext;
		free(pCurrentNode);
		pCurrentNode = NULL;
	}
	free(pList);
	pList = NULL;
}

int	getPolyListLength(PolyList *pList)
{
	if (!pList)
	{
		printf("PolyList Non Existing!");
		return (ERROR);
	}
	return (pList->currentElementCount);
}
