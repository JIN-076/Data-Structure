#include "Graph_LL.h"

int main()
{
	LinkedGraph* Graph = NULL;
	int maxVertexCount = 6;
	GraphNode node;

	Graph = createLinkedDirectedGraph(maxVertexCount);
	printf("This Graph MaxVertexCount is %d\n", getMaxVertexCountLG(Graph));
	printf("This GraphType is %d\n", getGraphTypeLG(Graph));

	printf("Graph is Empty? : %d\n", isEmptyLG(Graph));

	addVertexLG(Graph, 0);
	printf("Now, VertexCount is %d\n", getVertexCountLG(Graph));

	addVertexLG(Graph, 1);
	printf("Now, VertexCount is %d\n", getVertexCountLG(Graph));

	addVertexLG(Graph, 2);
	printf("Now, VertexCount is %d\n", getVertexCountLG(Graph));

	addVertexLG(Graph, 3);
	printf("Now, VertexCount is %d\n", getVertexCountLG(Graph));

	printf("%d\n", addEdgewithWeightLG(Graph, 0, 1, 4));
	printf("Now, EdgeCount is %d\n", getEdgeCountLG(Graph));

	addEdgewithWeightLG(Graph, 0, 2, 3);
	printf("Now, EdgeCount is %d\n", getEdgeCountLG(Graph));

	addEdgewithWeightLG(Graph, 0, 3, 1);
	printf("Now, EdgeCount is %d\n", getEdgeCountLG(Graph));

	addEdgewithWeightLG(Graph, 1, 2, 4);
	printf("Now, EdgeCount is %d\n", getEdgeCountLG(Graph));

	addEdgewithWeightLG(Graph, 3, 2, 2);
	printf("Now, EdgeCount is %d\n", getEdgeCountLG(Graph));

	addEdgewithWeightLG(Graph, 3, 1, 1);
	printf("Now, EdgeCount is %d\n", getEdgeCountLG(Graph));

	printf("LinkedList Count : %d\n", getLinkedListLength(Graph->ppAdjEdge[0]));

	deleteGraphNode(Graph->ppAdjEdge[0], 2);
	deleteGraphNode(Graph->ppAdjEdge[1], 2);
	deleteGraphNode(Graph->ppAdjEdge[3], 2);

	printf("%d\n", findGraphNodePosition(Graph->ppAdjEdge[0], 2));

	displayLinkedGraph(Graph);
}
