/*
Algorithm for Breadth-First Search (BFS) in a Graph:
1.Graph Representation:
    Define a structure Graph to represent the graph.
    The structure contains the number of vertices (numVertices) and an adjacency matrix (adjMatrix) to represent edges.
2.Graph Creation:
    Create a function createGraph that takes the number of vertices as a parameter.
    Allocate memory for the Graph structure and initialize the adjacency matrix with false values.
3.Graph Destruction:
    Create a function destroyGraph that frees the memory allocated for the Graph structure.
4.Adding Edges:
    Create a function addEdge that takes the Graph, start vertex, and end vertex as parameters.
    Update the adjacency matrix to mark the existence of an edge between the start and end vertices.
    Breadth-First Search (BFS):
5.Create a function BFS that takes the Graph and the starting vertex as parameters.
    Initialize a boolean array visited to keep track of visited vertices.
    Initialize a queue (front and rear indices) for BFS traversal.
    Mark the starting vertex as visited, enqueue it, and enter the BFS loop.
    Dequeue a vertex, print it, and enqueue its unvisited neighbors.
    Continue until the queue is empty.
6.Main Function:
    In the main function:
    Create a graph with 4 vertices using createGraph.
    Add edges to the graph using addEdge.
    Perform BFS traversal starting from vertex 2 using BFS.
    Print the result.
7.Memory Cleanup: In the main function, destroy the graph using destroyGraph to free allocated memory.
8. Output: The BFS traversal result starting from vertex 2 is printed to the console.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Struct definition without typedef
struct Graph
{
    int numVertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a graph
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            graph->adjMatrix[i][j] = false;
        }
    }
    return graph;
}

// Function to destroy a graph
void destroyGraph(struct Graph *graph)
{
    free(graph);
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int startVertex, int endVertex)
{
    graph->adjMatrix[startVertex][endVertex] = true;
}

// Breadth-First Search function
void BFS(struct Graph *graph, int startVertex)
{
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front != rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int adjacentVertex = 0; adjacentVertex < graph->numVertices; adjacentVertex++)
        {
            if (graph->adjMatrix[currentVertex][adjacentVertex] && !visited[adjacentVertex])
            {
                visited[adjacentVertex] = true;
                queue[rear++] = adjacentVertex;
            }
        }
    }
}

int main()
{
    // Create a graph
    struct Graph *graph = createGraph(4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    // Perform BFS traversal starting from vertex 2
    printf("Breadth First Traversal (starting from vertex 2):\n");
    BFS(graph, 2);

    // Destroy the graph
    destroyGraph(graph);

    return 0;
}
