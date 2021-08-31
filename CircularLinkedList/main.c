#include "CircularLinkedList.h"
#include <stdio.h>

int main()
{
	LinkedList* pList = NULL;
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

		int c = 3;
		node.data = &c;
		addLLElement(pList, 0, node);

		displayLinkedList(pList);

		removeLLElement(pList, 0);

		displayLinkedList(pList);

		deleteLinkedList(pList);
	}
	return 0;
}
