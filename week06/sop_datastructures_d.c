/*
Name: RICHOZ Julien & RICCI Paul
Date: 11.04.2024
Program runs (yes or no, because): Yes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ***** DATA STRUCTURE FOR DIGRAPH *****

struct NodeLinkedList
{
    int data;
    struct NodeLinkedList *next;
};

struct DiGraph
{
    int n; // Nodes quantity
    int m; // Arcs quantity
    struct NodeLinkedList **adjacencyList;
};

// ***** CREATE DIGRAPH  *****

struct DiGraph *createDiGraph(int nodeQty)
{
    // Malloc for a DiGraph
    struct DiGraph *graph = malloc(sizeof(struct DiGraph));
    if (graph == NULL)
    {
        fprintf(stderr, "Malloc failed...\n");
        exit(1);
    }
    // Malloc for each pointer to an adjacencyList
    graph->adjacencyList = malloc(nodeQty * sizeof(struct NodeLinkedList *));
    if (graph->adjacencyList == NULL)
    {
        fprintf(stderr, "Malloc failed...\n");
        exit(1);
    }
    // Init graph properties
    graph->n = nodeQty;
    graph->m = 0;
    // Init adjacencyList to NULL (we cannot know the arcs qty yet)
    for (int i = 0; i < nodeQty; i++)
    {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

// ***** CONNECT *****

void connect(struct DiGraph *graph, int n, int m)
{
    // Malloc a new Node (for m)
    struct NodeLinkedList *newNode = malloc(sizeof(struct NodeLinkedList));
    if (newNode == NULL)
    {
        fprintf(stderr, "Malloc failed...\n");
        exit(1);
    }
    // Assign the data as m
    newNode->data = m;
    // Insert at the beginning of the adjacentList of n
    if (graph->adjacencyList[n] == NULL)
    {
        // If the list is empty, set the new node as the head
        newNode->next = NULL;
        graph->adjacencyList[n] = newNode;
    }
    else
    {
        // If the list is not empty, insert the new node at the beginning
        newNode->next = graph->adjacencyList[n];
        graph->adjacencyList[n] = newNode;
    }
    // Adjust Arc quantity of graph
    graph->m++;
}

// ***** PRINT GRAPH *****

void printGraph(struct DiGraph *graph)
{
    printf("Nodes quantity : %d\n", graph->n);
    printf("Arcs quantity : %d\n", graph->m);
    for (int i = 0; i < graph->n; i++)
    {
        printf("Node %d / adjacencyList : ", i);
        struct NodeLinkedList *iterator = graph->adjacencyList[i];
        while (iterator != NULL)
        {
            printf("%d ", iterator->data);
            iterator = iterator->next;
        }
        printf(".\n");
    }
}

// ***** FREE GRAPH *****

void freeGraph(struct DiGraph *graph)
{
    // First : Free all the adjacencyList
    for (int i = 0; i < graph->n; i++)
    {
        struct NodeLinkedList *iterator = graph->adjacencyList[i];
        while (iterator != NULL)
        {
            struct NodeLinkedList *temp = iterator;
            iterator = iterator->next;
            free(temp); // free all the adjacencyList
        }
    }
    // Second : Free the Pointer to the adjacency lists
    free(graph->adjacencyList);
    // Third : Free the struct graph (i.e. graph->n and graph->m)
    free(graph);
}

// ***** MAIN *****

int main(int argc, char const *argv[])
{
    printf("\n");

    /*
        0 - > 1
        |     |
        v     v
        2 - > 3 - > 4
    */

    // Create a directed graph with 5 nodes
    struct DiGraph *graph = createDiGraph(5);

    // Connect nodes to form a simple graph structure
    connect(graph, 0, 1);
    connect(graph, 0, 2);
    connect(graph, 1, 3);
    connect(graph, 2, 3);
    connect(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Free the graph
    freeGraph(graph);

    return 0;
}
