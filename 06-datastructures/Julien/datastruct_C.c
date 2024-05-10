// Exercice C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
// main structure to represent the stack
struct StackNode
{
    int data; // payload hard-coded to int
    struct StackNode* next;
};
 
// Structure to keep track of the head and tail of the queue
struct Queue {
    struct StackNode* head;
    struct StackNode* tail;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    if(stackNode == NULL)
    {
        // failed to allocate memory
        fprintf(stderr, "Couldn't allocate memory\n");
        exit(1);
    }
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(struct Queue* queue)
{
    return queue->head == NULL;
}

// Enqueue: Add a new node at the end of the queue
void enqueue(struct Queue* queue, int data) {
    struct StackNode* temp = newNode(data);
    if (queue->tail != NULL) {
        queue->tail->next = temp;
    }
    queue->tail = temp;
    if (queue->head == NULL) {
        queue->head = temp;
    }
    printf("%d enqueued to queue\n", data);
}

// Dequeue: Remove the node from the front of the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty");
    }
    struct StackNode* temp = queue->head;
    int data = temp->data;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    printf("%d dequeued from queue\n", data);
    return data;
}
 
int peek(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    printf("%d peeked from stack\n", queue->head->data);
    return queue->head->data;
}
 
int main()
{
    struct Queue queue = {NULL, NULL};

 
    peek(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    dequeue(&queue);
    peek(&queue);
 
    return 0;
}