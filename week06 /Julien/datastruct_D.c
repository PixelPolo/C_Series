#include <stdio.h>
#include <stdlib.h>

// Definition for a directed graph node
struct node {
    int data;
    int num_edges;             // Number of edges from this node
    struct node **edges;       // Array of pointers to other nodes
};

// Allocates a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->num_edges = 0;      // No edges initially
    node->edges = NULL;       // No edges array initially
    return node;
}

// Connect two nodes with a directed edge from src to dst
void connect(struct node *src, struct node *dst) {
    // Increase the number of edges and reallocate memory for the edges array
    src->num_edges++;
    src->edges = realloc(src->edges, src->num_edges * sizeof(struct node*));
    // Add the destination node to the edges array
    src->edges[src->num_edges - 1] = dst;
}

int main() {
    struct node *node1 = newNode(1);
    struct node *node2 = newNode(2);
    struct node *node3 = newNode(3);

    // Connect nodes
    connect(node1, node2);  // Node 1 -> Node 2
    connect(node1, node3);  // Node 1 -> Node 3

    // Print data of node1's first connected node
    if (node1->num_edges > 0) {
        printf("Node %d is connected to Node %d\n", node1->data, node1->edges[0]->data);
    }

    // Clean up would involve freeing all nodes and their edges array
    free(node1->edges);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}