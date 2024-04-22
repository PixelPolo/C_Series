#include <stdio.h>
#include <stdlib.h>

// A: Some Linked List Data Structures
// 1. linked list
struct linkedList{
    int data;
    struct linkedList* next;
};

// 2. double linked list
struct doubleLinkedList{
    int data;
    struct doubleLinkedList* next;
    struct doubleLinkedList* prev;
};

// 3. Linked binary tree
struct binaryTree{
    int data;
    struct binaryTree* left;
    struct binaryTree* right;
};

int main()
{
    return 0;
}