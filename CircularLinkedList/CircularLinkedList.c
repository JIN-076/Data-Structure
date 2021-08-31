#include "CircularLinkedList.h"
#include "stdio.h"
#include "stdlib.h"

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
	ListNode* pLastNode = NULL;
	ListNode* pNewNode = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL)
			{
				*pNewNode = element;
				pNewNode->pLink = NULL;

				if (position == 0)
				{
					if (pList->currentElementCount == 0)
					{
						pList->headerNode.pLink = pNewNode;
						pNewNode->pLink = pNewNode;
					}
					else
					{
						pLastNode = pList->headerNode.pLink;
						while (pLastNode->pLink != pList->headerNode.pLink)
							pLastNode = pLastNode->pLink;
						pList->headerNode.pLink = pNewNode;
						pNewNode->pLink = pLastNode->pLink;
						pLastNode->pLink = pNewNode;
					}
				}
				else
				{
					pPreNode = &(pList->headerNode);
					for (int i = 0; i < position; i++)
						pPreNode = pPreNode->pLink;
					pNewNode->pLink = pPreNode->pLink;
					pPreNode->pLink = pNewNode;
				}
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
	ListNode* pPreNode = NULL;
	ListNode* pLastNode = NULL;
	ListNode* pDelNode = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position < pList->currentElementCount)
		{
			if (position == 0)
			{
				pDelNode = pList->headerNode.pLink;
				if (pList->currentElementCount == 1)
				{
					free(pDelNode);
					pList->headerNode.pLink = NULL;
				}
				else
				{
					pLastNode = pList->headerNode.pLink;
					while (pLastNode->pLink != pList->headerNode.pLink)
						pLastNode = pLastNode->pLink;
					pLastNode->pLink = pDelNode->pLink;
					pList->headerNode.pLink = pDelNode->pLink;
					free(pDelNode);
				}
			}
			else
			{
				pPreNode = &(pList->headerNode);
				for (int i = 0; i < position; i++)
					pPreNode = pPreNode->pLink;
				pDelNode = pPreNode->pLink;
				pPreNode->pLink = pDelNode->pLink;
				free(pDelNode);
			}
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
	ListNode* pNode = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position < pList->currentElementCount)
		{
			pNode = &(pList->headerNode);
			for (int i = 0; i <= position; i++)
				pNode = pNode->pLink;
		}
	}
	return pNode;
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

