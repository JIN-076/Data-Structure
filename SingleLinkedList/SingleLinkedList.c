#include "SinglyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* createLinkedList()
{
	LinkedList* List = NULL;
	List = (LinkedList*)malloc(sizeof(LinkedList));
	if (List != NULL)
	{
		List->currentElementCount = 0;
		List->headerNode.data = 0;
		List->headerNode.pLink = 0;
	}
	else
	{
		printf("Memory Allocation Failure!\n");
		return NULL;
	}
	return List;
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	int flag = FALSE;
	ListNode* pPreNode = NULL;
	ListNode* pNewNode = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL)
			{
				(*pNewNode).data = element.data;
				pNewNode->pLink = NULL;
				pPreNode = &(pList->headerNode);
				for (int i = 0; i < position; i++)
					pPreNode = pPreNode->pLink;
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
				pList->currentElementCount++;
				flag = TRUE;
			}
			else
			{
				printf("malloc failure!\n");
				return flag;
			}
		}
		else
			printf("You Can't add new element. This position is Out of Range\n");
	}
	return flag;
}

int removeLLElement(LinkedList* pList, int position)
{
	int flag = FALSE;
	int ArrayCount = 0;
	ListNode* pPreNode = NULL;
	ListNode* pDelNode = NULL;
	if (pList != NULL)
	{
		ArrayCount = getLinkedListLength(pList);
		if (position >= 0 && position < ArrayCount)
		{
			pPreNode = &(pList->headerNode);
			for (int i = 0; i < position; i++)
				pPreNode = pPreNode->pLink;
			pDelNode = pPreNode->pLink;
			pPreNode->pLink = pDelNode->pLink;
			free(pDelNode);
			pList->currentElementCount--;
			flag = TRUE;
		}
		else
			printf("You Can't remove element. This position is Out of Range\n");
	}
	return flag;
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode* List = NULL;
	ListNode* pNode = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position < pList->currentElementCount)
		{
			pNode = &(pList->headerNode);
			for (int i = 0; i <= position; i++)
				pNode = pNode->pLink;
			List = pNode;
		}
	}
	return List;
}

void clearLinkedList(LinkedList* pList)
{
	if (pList != NULL)
	{
		if (pList->currentElementCount > 0)
		{
			removeLLElement(pList, 0);
		}
	}
}

int getLinkedListLength(LinkedList* pList)
{
	int Length = 0;
	if (pList != NULL)
	{
		Length = pList->currentElementCount;
	}
	return Length;
}

void deleteLinkedList(LinkedList* pList)
{
	if (pList != NULL)
	{
		clearLinkedList(pList);
		free(pList);
	}
}

int isEmpty(LinkedList* pList)
{
	int flag = FALSE;
	if (pList != NULL)
	{
		if (pList->currentElementCount == 0)
			flag = TRUE;
	}
	return flag;
}

void displayLinkedList(LinkedList* pList)
{
	if (pList != NULL)
	{
		printf("현재 원소의 개수 : %d\n", pList->currentElementCount);
		for (int i = 0; i < pList->currentElementCount; i++)
			printf("%d ", *(int*)getLLElement(pList, i)->data);
	}
	else
		printf("There is no element\n");
	printf("\n");
}

int reverseLinkedList(LinkedList *pList)
{
	ListNode* pHeadNode;
	ListNode* pPreNode;
	ListNode* pCurrNode;
	ListNode* pNextNode;

	if (pList != NULL)
	{
		if (pList->currentElementCount < 2)
			return TRUE;
		pHeadNode = &(pList->headerNode);
		pPreNode = NULL;
		pCurrNode = pHeadNode->pLink;
		pNextNode = pCurrNode->pLink;

		while (pCurrNode != NULL)
		{
			pCurrNode->pLink = pPreNode;
			pPreNode = pCurrNode;
			pCurrNode = pNextNode;
			if (pNextNode)
				pNextNode = pNextNode->pLink;
		}
		pHeadNode->pLink = pPreNode;
	}
	else
	{
		printf("Now Linked List is Non-Existing!\n");
		return ERROR;
	}
	return TRUE;
}
