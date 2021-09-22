#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GraphNodeType
{
	int vertex;
	int weight;
	struct GraphNodeType* pLink;
} GraphNode;

typedef struct LinkedListType
{
	int currentElementCount; // 현재 저장된 원소의 개수
	GraphNode headerNode; // 헤더 노드 (Header Node)
} LinkedList;

typedef struct LinkedGraphType
{
	int maxVertexCount;		// Maximum number of Nodes
	int currentVertexCount;	// The Number of Nodes used so far
	int currentEdgeCount;	// The Number of Edges used so far
	int graphType;			// Types -> 1 : Non-directed, 2 : Directed
	LinkedList** ppAdjEdge;	// 2D-LinkedList that stores Edges
	int *pVertex;			// 1D-array that stores Nodes
} LinkedGraph;

// Create a Non-Directinal Graph
// Create a Directional Graph
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// Remove the Graph
void deleteLinkedGraph(LinkedGraph* pGraph);

// The existence of Nodes in the Graph
int isEmptyLG(LinkedGraph* pGraph);

// Adding Nodes to the Graph
int addVertexLG(LinkedGraph* pGraph, int vertexID);

int getLinkedListLength(LinkedList* pList);
int addLLElement(LinkedList* pList, int position, GraphNode element);
int removeLLElement(LinkedList* pList, int position);

// Adding Edges to the Graph
// Adding Weights to the Graph
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// Checking Vertex is Valid
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// Remove the Node from the Graph
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// Remove Edges from the Graph
// Delete Node from the Graph
// Find Node Position from the Graph
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);

// Get EdgeCount
int getEdgeCountLG(LinkedGraph* pGraph);

// Get VertexCount
int getVertexCountLG(LinkedGraph* pGraph);

// Get MaxVertexCount
int getMaxVertexCountLG(LinkedGraph* pGraph);

// Get GraphType
int getGraphTypeLG(LinkedGraph* pGraph);

// Output adjacent-List in the Graph
void displayLinkedGraph(LinkedGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE				1
#define FALSE				0

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#endif
