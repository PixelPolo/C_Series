/*
Name: RICHOZ Julien & RICCI Paul
Date: 11.04.2024
Program runs (yes or no, because): Yes
*/

#include <stdio.h>
#include <stdlib.h>

/*
    Linked Stack of int
*/

// ***** Node struct *****
struct NodeStack
{
    int data;
    struct NodeStack *next;
};

// ***** New Node *****
struct NodeStack *newNode(int data)
{
    // Malloc for new node
    struct NodeStack *node = malloc(sizeof(struct NodeStack));
    if (node == NULL)
    {
        printf("Malloc failed...\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL; // Will be top on push
    return node;
}

// ***** Is Empty *****
int isEmpty(struct NodeStack *top)
{
    return !top;
}

// ***** Push *****
void push(struct NodeStack **top, int data)
{
    struct NodeStack *nNode = newNode(data); // Create a new Node
    nNode->next = *top;                      // Insert at top
    *top = nNode;                            // Move top pointer
}

// ***** Peek *****
int peek(struct NodeStack *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        exit(2);
    }
    return top->data;
}

// ***** Pop *****
int pop(struct NodeStack **top)
{
    if (isEmpty(*top))
    {
        printf("Stack is empty\n");
        exit(3);
    }
    struct NodeStack *temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

// ***** Iteration *****
void printStack(struct NodeStack *top)
{
    printf("\n");
    struct NodeStack *iterator = top;
    while (iterator != NULL)
    {
        printf("%d\n", iterator->data);
        iterator = iterator->next;
    }
    free(iterator);
    printf("\n");
}

// ***** swap_ptr == swap top with top->next *****
void swap_ptr(struct NodeStack **top)
{
    if (*top != NULL && (*top)->next != NULL)
    {
        struct NodeStack *temp = *top;
        *top = temp->next; // Move *top to 2
        temp->next = (*top)->next; // 1 -> 3
        (*top)->next = temp; // 2 -> 1
    }
}

int main(int argc, char const *argv[])
{
    printf("\n");
    struct NodeStack *top = NULL;
    push(&top, 5);
    push(&top, 4);
    push(&top, 3);
    push(&top, 222);
    push(&top, 111);
    printf("Iteration Before Swap\n");
    printStack(top);
    swap_ptr(&top); // SWAP
    printf("Iteration After Swap\n");
    printStack(top);
    return 0;
}
