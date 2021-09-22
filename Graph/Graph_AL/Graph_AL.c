#include "Graph_AL.h"

// Create a Non-Directinal Graph
// Create a Directional Graph
ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph* pReturn = NULL;
	if (maxVertexCount > 0)
	{
		pReturn = (ArrayGraph*)malloc(sizeof(ArrayGraph));

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

	pReturn->ppAdjEdge = (int**)malloc(sizeof(int*) * maxVertexCount);
	for (int i = 0; i < maxVertexCount; i++)
		pReturn->ppAdjEdge[i] = (int*)malloc(sizeof(int) * maxVertexCount);

	for (int i = 0; i < maxVertexCount; i++)
		memset(pReturn->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);

	return (pReturn);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph* pReturn = NULL;
	pReturn = createArrayGraph(maxVertexCount);
	pReturn->graphType = GRAPH_DIRECTED;
	return (pReturn);
}

// Remove the Graph
void deleteArrayGraph(ArrayGraph* pGraph)
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
int isEmptyAG(ArrayGraph* pGraph)
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
int addVertexAG(ArrayGraph* pGraph, int vertexID)
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
		return (flag);
	}
}

// Adding Edges to the Graph
// Adding Weights to the Graph
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, 1));
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	int flag = SUCCESS;

	if (pGraph != NULL)
	{
		if (pGraph->pVertex[fromVertexID] == USED && pGraph->pVertex[toVertexID] == USED)
		{
			if (pGraph->ppAdjEdge[fromVertexID][toVertexID] == 0)
			{
				pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
				if (pGraph->graphType == GRAPH_UNDIRECTED)
					pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
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
int checkVertexValid(ArrayGraph* pGraph, int vertexID)
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
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	int flag = SUCCESS;

	if (pGraph != NULL)
	{
		if (checkVertexValid(pGraph, vertexID) == TRUE)
		{
			for (int i = 0; i < pGraph->maxVertexCount; i++)
			{
				pGraph->ppAdjEdge[vertexID][i] = 0;
				pGraph->ppAdjEdge[i][vertexID] = 0;
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
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	int flag = SUCCESS;

	if (pGraph != NULL)
	{
		if (pGraph->pVertex[fromVertexID] == USED && pGraph->pVertex[toVertexID] == USED)
		{
			if (pGraph->ppAdjEdge[fromVertexID][toVertexID] != 0)
			{
				pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
				if (pGraph->graphType == GRAPH_UNDIRECTED)
					pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
			}
		}
		else
		{
			printf("Now, This Edge is Non-Existing!\n");
			flag = FAIL;
		}
	}
	else
	{
		printf("Now, toVertexID or fromVertexID is Non-Existing!\n");
		flag = FAIL;
	}
	return (flag);
}

// Output adjacent-matrix in the Graph
void displayArrayGraph(ArrayGraph* pGraph)
{

}
