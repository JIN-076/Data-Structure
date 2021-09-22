#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayGraphType
{
	int maxVertexCount;		// Maximum number of Nodes
	int currentVertexCount;	// The Number of Nodes used so far
	int graphType;			// Types -> 1 : Non-directed, 2 : Directed
	int **ppAdjEdge;		// 2D-array that stores Edges
	int *pVertex;			// 1D-array that stores Nodes
} ArrayGraph;

// Create a Non-Directinal Graph
// Create a Directional Graph
ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

// Remove the Graph
void deleteArrayGraph(ArrayGraph* pGraph);

// The existence of Nodes in the Graph
int isEmptyAG(ArrayGraph* pGraph);

// Adding Nodes to the Graph
int addVertexAG(ArrayGraph* pGraph, int vertexID);

// Adding Edges to the Graph
// Adding Weights to the Graph
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// Checking Vertex is Valid
int checkVertexValid(ArrayGraph* pGraph, int vertexID);

// Remove the Node from the Graph
int removeVertexAG(ArrayGraph* pGraph, int vertexID);

// Remove Edges from the Graph
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

// Output adjacent-matrix in the Graph
void displayArrayGraph(ArrayGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

// Wheter or not to use Status
#define USED				1
#define NOT_USED			0

// Whether the Calculation of the Graph is Successful or not
#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

// Non-directional / Directional Graph
#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
