#include "CircularQueue.h"

int main()
{
	CircularQueue *cq = NULL;
	ArrayListNode node;
	ArrayListNode *pNode;
	int maxElementCount = 4;

	cq = createCircularQueue(maxElementCount);
	if (cq != NULL)
	{
		int a = 1;
		node.data = &a;
		enqueue(cq, node);

		int b = 2;
		node.data = &b;
		enqueue(cq, node);

		int c = 3;
		node.data = &c;
		enqueue(cq, node);

		int d = 4;
		node.data = &d;
		enqueue(cq, node);

		displayCircularQueue(cq);

		pNode = dequeue(cq);

		if (pNode != NULL)
		{
			printf("dequeue : %d\n", *(int*)pNode->data);
			free(pNode);
		}

		displayCircularQueue(cq);

		pNode = peek(cq);

		if (pNode != NULL)
		{
			printf("peek : %d\n", *(int*)pNode->data);
			free(pNode);
		}

		int e = 5;
		node.data = &e;
		enqueue(cq, node);

		displayCircularQueue(cq);
	}
}
