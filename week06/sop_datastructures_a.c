/*
Name: RICHOZ Julien & RICCI Paul
Date: 11.04.2024
Program runs (yes or no, because): Yes
*/

#include <stdio.h>
#include <stdlib.h>

// ***** Linked List *****

struct linkedListNode
{
    int data;
    struct linkedListNode *next;
};

// ***** Doubly Linked List *****

struct DoublyLinkedNode
{
    int data;
    struct DoublyLinkedNode *prev;
    struct DoublyLinkedNode *next;
};

// ***** Linked Binary Tree *****

struct LinkedBinTreeNode
{
    int data;
    struct LinkedBinTreeNode *left;
    struct LinkedBinTreeNode *right;
};

// ***** Linked List Test *****

void linkedListTest()
{
    // Nodes declaration
    struct linkedListNode *nodeOne = malloc(sizeof(struct linkedListNode));
    struct linkedListNode *nodeTwo = malloc(sizeof(struct linkedListNode));
    struct linkedListNode *nodeThree = malloc(sizeof(struct linkedListNode));
    // Nodes data
    nodeOne->data = 1;
    nodeTwo->data = 2;
    nodeThree->data = 3;
    // Link construction
    struct linkedListNode *head = nodeOne;
    nodeOne->next = nodeTwo;
    nodeTwo->next = nodeThree;
    nodeThree->next = NULL;
    // Iteration
    printf("\nLinked List Iteration\n");
    struct linkedListNode *iterator = head;
    while (iterator != NULL)
    {
        printf("%d\n", iterator->data);
        iterator = iterator->next;
    }
    // free
    free(nodeOne);
    free(nodeTwo);
    free(nodeThree);
    printf("\n");
}

// ***** Doubly Linked List Test *****

void doublyLinkedListTest()
{
    // Nodes declaration
    struct DoublyLinkedNode *nodeOne = malloc(sizeof(struct DoublyLinkedNode));
    struct DoublyLinkedNode *nodeTwo = malloc(sizeof(struct DoublyLinkedNode));
    struct DoublyLinkedNode *nodeThree = malloc(sizeof(struct DoublyLinkedNode));
    // Nodes data
    nodeOne->data = 1;
    nodeTwo->data = 2;
    nodeThree->data = 3;
    // Link construction
    struct DoublyLinkedNode *head = nodeOne;
    struct DoublyLinkedNode *tail = nodeThree;
    nodeOne->next = nodeTwo;
    nodeOne->prev = NULL;
    nodeTwo->next = nodeThree;
    nodeTwo->prev = nodeOne;
    nodeThree->next = NULL;
    nodeThree->prev = nodeTwo;
    // Forward iteration
    printf("\nDoubly Linked List Iteration ->\n");
    struct DoublyLinkedNode *iterator = head;
    while (iterator != NULL)
    {
        printf("%d\n", iterator->data);
        iterator = iterator->next;
    }
    // Backward iteration
    printf("\nDoubly Linked List Iteration <-\n");
    iterator = tail;
    while (iterator != NULL)
    {
        printf("%d\n", iterator->data);
        iterator = iterator->prev;
    }
    // free
    free(nodeOne);
    free(nodeTwo);
    free(nodeThree);
    printf("\n");
}

// ***** Linked Binary Tree Test *****

void traversePostorder(struct LinkedBinTreeNode *node)
{
    if (node == NULL)
        return;
    traversePostorder(node->left);
    traversePostorder(node->right);
    printf("%d\n", node->data);
}

void LinkedBinTreeTest()
{
    // Nodes declaration
    struct LinkedBinTreeNode *nodeOne = malloc(sizeof(struct LinkedBinTreeNode));
    struct LinkedBinTreeNode *nodeTwo = malloc(sizeof(struct LinkedBinTreeNode));
    struct LinkedBinTreeNode *nodeThree = malloc(sizeof(struct LinkedBinTreeNode));
    // Nodes data
    nodeOne->data = 1;
    nodeTwo->data = 2;
    nodeThree->data = 3;
    // Link construction
    nodeOne->left = nodeTwo;
    nodeOne->right = nodeThree;
    nodeTwo->left = NULL;
    nodeTwo->right = NULL;
    nodeThree->left = NULL;
    nodeThree->right = NULL;
    // Iteration
    printf("\nLinked Binary Tree PostOrder\n");
    traversePostorder(nodeOne);
    // free
    free(nodeOne);
    free(nodeTwo);
    free(nodeThree);
    printf("\n");
}

// ***** Main *****

int main(int argc, char const *argv[])
{
    linkedListTest();
    doublyLinkedListTest();
    LinkedBinTreeTest();
    return 0;
}
