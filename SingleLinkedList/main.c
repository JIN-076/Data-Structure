#include "SinglyLinkedList.h"
#include <stdio.h>

int main()
{
	int ArrayCount = 0;
	LinkedList* pList = NULL;
	ListNode* pNode = NULL;
	ListNode node;

	pList = createLinkedList();

	if (pList != NULL)
	{
		int a = 1;
		node.data = &a;
		addLLElement(pList, 0, node);

		int b = 2;
		node.data = &b;
		addLLElement(pList, 1, node);

		int c = 5;
		node.data = &c;
		addLLElement(pList, 2, node);

		int d = 10;
		node.data = &d;
		addLLElement(pList, 3, node);

		int e = 13;
		node.data = &e;
		addLLElement(pList, 4, node);

		int f = 15;
		node.data = &f;
		addLLElement(pList, 5, node);

		displayLinkedList(pList);

		removeLLElement(pList, 0);

		displayLinkedList(pList);

		reverseLinkedList(pList);

		displayLinkedList(pList);
	}
}
