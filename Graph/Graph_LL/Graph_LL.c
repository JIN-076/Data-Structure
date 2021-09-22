#include "Graph_LL.h"

// Create a Non-Directinal Graph
// Create a Directional Graph
LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph* pReturn = NULL;
	if (maxVertexCount  > 0)
	{
		pReturn = (LinkedGraph*)malloc(sizeof(LinkedGraph));

		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
	}
	else
	{
		printf("You Must Checking maxVertexCount!\n");
		return (NULL);
	}
	pReturn->pVertex = (int*)malloc(sizeof(int) * maxVertexCount);
	memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);

	pReturn->ppAdjEdge = (LinkedList**)malloc(sizeof(LinkedList) * maxVertexCount);
	for (int i = 0; i < maxVertexCount; i++)
		pReturn->ppAdjEdge[i] = (LinkedList*)malloc(sizeof(LinkedList));

	for (int i = 0; i < maxVertexCount; i++)
		memset(pReturn->ppAdjEdge[i], 0, sizeof(LinkedList));

	return (pReturn);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph* pReturn = NULL;
	pReturn = createLinkedGraph(maxVertexCount);
	pReturn->graphType = GRAPH_DIRECTED;
	return (pReturn);
}

// Remove the Graph
void deleteLinkedGraph(LinkedGraph* pGraph)
{
	if (pGraph != NULL)
	{
		free(pGraph->pVertex);
		for (int i = 0; i < pGraph->maxVertexCount; i++)
			free(pGraph->ppAdjEdge[i]);
		free(pGraph->ppAdjEdge);
		free(pGraph);
	}
}

// The existence of Nodes in the Graph
int isEmptyLG(LinkedGraph* pGraph)
{
	int flag = FALSE;

	if (pGraph != NULL)
	{
		if (pGraph->currentVertexCount == 0)
			flag = TRUE;
	}
	return (flag);
}

// Adding Nodes to the Graph
int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	int flag = SUCCESS;

	if (pGraph != NULL)
	{
		if (vertexID < pGraph->maxVertexCount && pGraph->pVertex[vertexID] == NOT_USED)
		{
			pGraph->pVertex[vertexID] = USED;
			pGraph->currentVertexCount++;
		}
		else
		{
			printf("This Node is Now Existing or Exceeded the MaxVertexCount!\n");
			flag = FAIL;
		}
	}
	return (flag);
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

int addLLElement(LinkedList* pList, int position, GraphNode element)
{
	int flag = FALSE;
	GraphNode* pPreNode = NULL;
	GraphNode* pNewNode = NULL;
	printf("Count : %d\n", position);
	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pNewNode = (GraphNode*)malloc(sizeof(GraphNode));
			if (pNewNode != NULL)
			{
				(*pNewNode).vertex = element.vertex;
				(*pNewNode).weight = element.weight;
				pNewNode->pLink = NULL;
				pPreNode = &(pList->headerNode);
				for (int i = 0; i < position; i++)
					pPreNode = pPreNode->pLink;
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
				pList->currentElementCount++;
				printf("pList->currentElementCount : %d\n", pList->currentElementCount);
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
	GraphNode* pPreNode = NULL;
	GraphNode* pDelNode = NULL;
	if (pList != NULL)
	{
		ArrayCount = getLinkedListLength(pList);
		printf("Linked List Count : %d\n", ArrayCount);
		if (position >= 0 && position < ArrayCount)
		{
			pPreNode = &(pList->headerNode);
			for (int i = 0; i < position; i++) {
				pPreNode = pPreNode->pLink;
				printf("%d : %d\n", i, pPreNode->vertex);
			}
			pDelNode = pPreNode->pLink;
			printf("Delete Node : %d\n", pDelNode->vertex);
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

// Adding Edges to the Graph
// Adding Weights to the Graph
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, 1));
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	int flag = SUCCESS;

	if (pGraph != NULL)
	{
		if (pGraph->pVertex[fromVertexID] == USED && pGraph->pVertex[toVertexID] == USED)
		{
			// fromVertexID번째의 LinkedList에서 toVertexID가 존재한다면
			if (findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID) == 0)
			{
				GraphNode toVertexNode;
				toVertexNode.vertex = toVertexID;
				toVertexNode.weight = weight;
				//pGraph->ppAdjEdge[toVertexID]->currentElementCount++;
				//printf("CurrentElementCount : %d\n", pGraph->ppAdjEdge[toVertexID]->currentElementCount);
				addLLElement(pGraph->ppAdjEdge[fromVertexID], pGraph->ppAdjEdge[toVertexID]->currentElementCount, toVertexNode);
				pGraph->currentEdgeCount++;

				if (getGraphTypeLG(pGraph) == GRAPH_UNDIRECTED)
				{
					GraphNode* fromVertexNode = (GraphNode*)malloc(sizeof(GraphNode));
					fromVertexNode->vertex = fromVertexID;
					fromVertexNode->weight = weight;
					fromVertexNode->pLink = NULL;
				}
			}
			else
			{
				printf("Now, Existing Edges!\n");
				flag = FAIL;
			}
		}
		else
		{
			printf("toVertexID or fromVertexID is Non-Existing!\n");
			flag = FAIL;
		}
	}
	return (flag);
}

// Checking Vertex is Valid
int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	int flag = FALSE;

	if (pGraph != NULL)
	{
		if (pGraph->pVertex[vertexID] == USED)
			flag = TRUE;
	}
	return (flag);
}

// Remove the Node from the Graph
int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	int flag = SUCCESS;

	if (pGraph != NULL)
	{
		if (checkVertexValid(pGraph, vertexID) == TRUE)
		{
			GraphNode* pNode_first = (GraphNode*)malloc(sizeof(GraphNode));
			GraphNode* pNode_Second = (GraphNode*)malloc(sizeof(GraphNode));
			pNode_first = &(pGraph->ppAdjEdge[vertexID]->headerNode);
			for (int i = 0; i < pGraph->maxVertexCount; i++)
			{
				pNode_first->weight = 0;
				pNode_Second->weight = 0;
				pNode_first = pNode_first->pLink;
				pNode_Second = pNode_Second->pLink;
			}
			pGraph->pVertex[vertexID] = NOT_USED;
			pGraph->currentVertexCount--;
		}
		else
		{
			printf("Now, This Node is Non-Existing. You can't Remove this vertex!\n");
			flag = FAIL;
		}
	}
	return (flag);
}

// Remove Edges from the Graph
// Delete Node from the Graph
// Find Node Position from the Graph
// int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
// {

// }

void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	GraphNode* pDelNode = NULL;
	int DelIdx = 0;

	if (pList != NULL)
	{
		pDelNode = &(pList->headerNode);
		printf("pDelNode : %d\n", (*pDelNode).vertex);
		while (pDelNode != NULL)
		{
			if ((*pDelNode).vertex == delVertexID) {
				printf("DelIdx : %d\n", DelIdx);
				printf("%d\n", (*pDelNode).vertex);
				removeLLElement(pList, DelIdx - 1);
			}
			pDelNode = pDelNode->pLink;
			DelIdx++;
		}
	}
}

int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	int weight = 0;
	GraphNode* pNode = NULL;

	if (pList != NULL)
	{
		pNode = &(pList->headerNode);
		while (pNode != NULL)
		{
			if ((*pNode).vertex == vertexID)
			{

				weight = (*pNode).weight;
				return (weight);
			}
			pNode = pNode->pLink;
		}
	}
	return (weight);
}

// Get EdgeCount
int getEdgeCountLG(LinkedGraph* pGraph)
{
	int EdgeCount;
	EdgeCount = 0;

	if (pGraph != NULL)
		EdgeCount = pGraph->currentEdgeCount;

	return (EdgeCount);
}

// Get VertexCount
int getVertexCountLG(LinkedGraph* pGraph)
{
	int VertexCount;
	VertexCount = 0;

	if (pGraph != NULL)
		VertexCount = pGraph->currentVertexCount;

	return (VertexCount);
}

// Get MaxVertexCount
int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	int MaxVertexCount;
	MaxVertexCount = 0;

	if (pGraph != NULL)
		MaxVertexCount = pGraph->maxVertexCount;

	return (MaxVertexCount);
}

// Get GraphType
int getGraphTypeLG(LinkedGraph* pGraph)
{
	int GraphType;
	GraphType = 0;

	if (pGraph != NULL)
		GraphType = pGraph->graphType;

	return (GraphType);
}

// Output adjacent-List in the Graph
void displayLinkedGraph(LinkedGraph* pGraph)
{
	LinkedList* pList = NULL;
	GraphNode* pNode = NULL;

	for (int i = 0; i < getMaxVertexCountLG(pGraph); i++)
	{
		pList = pGraph->ppAdjEdge[i];
		printf("LinkedList of %d Idx : \n", i);
		pNode = &(pList->headerNode);
		pNode = pNode->pLink;
		while (pNode != NULL)
		{
			printf("Vertex : %d, Weight : %d\n", pNode->vertex, pNode->weight);
			pNode = pNode->pLink;
		}
	}
}
