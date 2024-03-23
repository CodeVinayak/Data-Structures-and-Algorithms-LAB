/*
Algorithm: Depth-First Search Traversal on an Undirected Graph
1.CreateGraph Function: 
Initialize a graph structure with a specified number of vertices and edges.
Allocate memory for the adjacency matrix to represent the graph.
Initialize the adjacency matrix with zeros.
Set specific edges in the adjacency matrix to 1 to represent the connections between vertices.
Return the initialized graph.

2.DepthFirstSearch Function:
Mark the current vertex as visited.
Print the value of the current vertex.
For each adjacent vertex:
If the adjacent vertex is not visited and there is a connection in the adjacency matrix:
Recursively call DepthFirstSearch on the adjacent vertex.

3.DepthFirstTraversal Function:
Initialize a visited array to keep track of visited vertices.
Iterate through each vertex in the graph:
If the vertex is not visited, call DepthFirstSearch on that vertex.

4.Main Function:
Create a graph using the CreateGraph function.
Add edges to the graph within the CreateGraph function.
Perform Depth-First Search traversal starting from vertex 0 using DepthFirstTraversal.
Print the result of the DFS traversal.

5.Free Memory:  Free the allocated memory for the adjacency matrix in the graph.
*/
#include <stdio.h>
#include <stdlib.h>

int visited[100];

struct Graph {
    int vertices;
    int edges;
    int** adjacencyMatrix;
};

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (!graph) {
        printf("Memory Error\n");
        return NULL;
    }

    graph->vertices = 7;
    graph->edges = 7;

    graph->adjacencyMatrix = (int**)malloc(graph->vertices * sizeof(int*));
    for (int i = 0; i < graph->vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(graph->vertices * sizeof(int));
    }

    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    graph->adjacencyMatrix[0][1] = graph->adjacencyMatrix[1][0] = 1;
    graph->adjacencyMatrix[0][2] = graph->adjacencyMatrix[2][0] = 1;
    graph->adjacencyMatrix[1][3] = graph->adjacencyMatrix[3][1] = 1;
    graph->adjacencyMatrix[1][4] = graph->adjacencyMatrix[4][1] = 1;
    graph->adjacencyMatrix[1][5] = graph->adjacencyMatrix[5][1] = 1;
    graph->adjacencyMatrix[1][6] = graph->adjacencyMatrix[6][1] = 1;
    graph->adjacencyMatrix[6][2] = graph->adjacencyMatrix[2][6] = 1;

    return graph;
}

void depthFirstSearch(struct Graph* graph, int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int adjacentVertex = 0; adjacentVertex < graph->vertices; adjacentVertex++) {
        if (!visited[adjacentVertex] && graph->adjacencyMatrix[vertex][adjacentVertex]) {
            depthFirstSearch(graph, adjacentVertex);
        }
    }
}

void depthFirstTraversal(struct Graph* graph) {
    for (int i = 0; i < 100; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            depthFirstSearch(graph, i);
        }
    }
}

int main() {
    // Create a graph
    struct Graph* graph = createGraph();

    // Add edges to the graph
    // (Already added in the createGraph function)

    // Perform DFS traversal starting from vertex 0
    printf("DFS Traversal starting from vertex 0:\n");
    depthFirstTraversal(graph);

    // Free allocated memory
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);

    return 0;
}
