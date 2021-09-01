#include "Deque.h"

int main()
{
	Deque dq;
	ListNode node;
	ListNode* pNode;
	int cnt = 0;
	createDeque(&dq);

	int a = 1;
	node.data = &a;
	pushFront(&dq, node);

	int b = 2;
	node.data = &b;
	pushFront(&dq, node);

	int c = 3;
	node.data = &c;
	pushFront(&dq, node);

	int d = 4;
	node.data = &d;
	pushFront(&dq, node);

	int e = 5;
	node.data = &e;
	pushFront(&dq, node);

	int f = 6;
	node.data = &f;
	pushFront(&dq, node);

	displayDeque(&dq);
}
