#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct ListNode
{
	int data;
	struct ListNode* pLink;
} ListNode;

typedef struct LinkedList
{
	int currentElementCount;
	ListNode headerNode;
} LinkedList;

LinkedList* createLinkedList()
{
	LinkedList* pList = NULL;
	pList = new LinkedList;
	if (pList != NULL)
		memset(pList, 0, sizeof(LinkedList));
	else
	{
		cout << "Error" << endl;
		return NULL;
	}
	return pList;
}

int main()
{
	ListNode* List = NULL;
	LinkedList* Linked = NULL;
	ListNode node;

	Linked = createLinkedList();

	printf("%d\n", Linked->currentElementCount);
	printf("%d\n", Linked->headerNode.data);
	printf("%p\n", &Linked->headerNode.pLink);
}
