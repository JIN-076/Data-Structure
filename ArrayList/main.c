#include "ArrayList.h"
#include <stdio.h>

int main()
{
	int ArrayCount = 6;
	ArrayList *pList = NULL;
	ArrayListNode node;

	pList = createArrayList(ArrayCount);

	if (pList != NULL)
	{
		int a = 1;
		node.data = &a;
		addALElement(pList, 0, node);

		printf("%d\n", *(int*)node.data);
		printf("%d\n", *(int*)(pList->pElement[0]).data);

		int b = 2;
		node.data = &b;
		addALElement(pList, 1, node);
		printf("%d\n", *(int*)(pList->pElement[1]).data);

		int c = 3;
		node.data = &c;
		addALElement(pList, 2, node);

		int d = 4;
		node.data = &d;
		addALElement(pList, 3, node);

		displayArrayList(pList);
		removeALElement(pList, 1);
		displayArrayList(pList);

		clearArrayList(pList);
		displayArrayList(pList);

		ArrayListNode* pNode = NULL;
		pNode = getALElement(pList, 1);
		printf("%d\n", *(int*)pNode->data);
	}
}
