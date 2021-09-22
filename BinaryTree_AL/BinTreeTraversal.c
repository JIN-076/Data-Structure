#include "BinTree.h"
#include "BinTreeTraversal.h"

void PreOrderBinTree(BinTree* pBinTree)
{
	if (pBinTree != NULL)
	{
		PreOrderBinTreeNode(pBinTree->pRootNode);
	}
}

void PreOrderBinTreeNode(BinTreeNode* pRootNode)
{
	if (pRootNode != NULL)
	{
		printf("%c -> ", pRootNode->data);
		PreOrderBinTreeNode(pRootNode->pLeftChild);
		PreOrderBinTreeNode(pRootNode->pRightChild);
	}
}

void InOrderBinTree(BinTree* pBinTree)
{
	if (pBinTree != NULL)
	{
		InOrderBinTreeNode(pBinTree->pRootNode);
	}
}

void InOrderBinTreeNode(BinTreeNode* pRootNode)
{
	if (pRootNode != NULL)
	{
		InOrderBinTreeNode(pRootNode->pLeftChild);
		printf("%c -> ", pRootNode->data);
		InOrderBinTreeNode(pRootNode->pRightChild);
	}
}

void PostOrderBinTree(BinTree* pBinTree)
{
	if (pBinTree != NULL)
	{
		PostOrderBinTreeNode(pBinTree->pRootNode);
	}
}

void PostOrderBinTreeNode(BinTreeNode* pRootNode)
{
	if (pRootNode != NULL)
	{
		PostOrderBinTreeNode(pRootNode->pLeftChild);
		PostOrderBinTreeNode(pRootNode->pRightChild);
		printf("%c -> ", pRootNode->data);
	}
}
