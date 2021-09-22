#include "BinTree.h"
#include "BinTreeTraversal.h"

int main()
{
	BinTree* pBinTree = NULL;
	BinTreeNode* pNode1 = NULL;
	BinTreeNode* pNode2 = NULL;
	BinTreeNode* pNode3 = NULL;
	BinTreeNode* pNode4 = NULL;
	BinTreeNode* pNode5 = NULL;
	BinTreeNode* pNode6 = NULL;
	BinTreeNode* pNode7 = NULL;

	BinTreeNode node = { 0, };

	node.data = 'A';
	pBinTree = makeBinTree(node);

	if (pBinTree != NULL)
	{
		pNode1 = getRootNodeBT(pBinTree);

		node.data = 'B';
		pNode2 = insertLeftChildNodeBT(pNode1, node);

		node.data = 'C';
		pNode3 = insertRightChildNodeBT(pNode1, node);

		node.data = 'D';
		pNode4 = insertLeftChildNodeBT(pNode2, node);

		node.data = 'E';
		pNode5 = insertRightChildNodeBT(pNode2, node);

		node.data = 'F';
		pNode6 = insertLeftChildNodeBT(pNode3, node);

		node.data ='G';
		pNode7 = insertRightChildNodeBT(pNode3, node);
	}

	if (pBinTree != NULL)
	{
		printf("PreOrder Traversal\n");
		PreOrderBinTree(pBinTree);
		printf("\n\n");

		printf("InOrder Traversal\n");
		InOrderBinTree(pBinTree);
		printf("\n\n");

		printf("PostOrder Traversal\n");
		PostOrderBinTree(pBinTree);
		printf("\n");

		deleteBinTree(pBinTree);
	}
	return (0);
}
