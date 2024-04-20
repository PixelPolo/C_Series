/*
Name: RICHOZ Julien & RICCI Paul
Date: 11.04.2024
Program runs (yes or no, because): Yes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Generic Linked Queue implementation
*/

// ***** Node struct *****
struct Node
{
    void *data;
    struct Node *next;
};

// ***** Queue struct *****
struct LinkedQueue
{
    int maxSize;
    int size;
    struct Node *first;
    struct Node *last;
};

// ***** Create LinkedQueue *****
struct LinkedQueue *createLinkedQueue(int size)
{
    // Malloc for the whole queue
    struct LinkedQueue *queue = malloc(size * sizeof(struct LinkedQueue));
    if (queue == NULL)
    {
        fprintf(stderr, "Malloc failed...\n");
        exit(1);
    }
    // Set the maxSize and size of the Queue
    queue->maxSize = size;
    queue->size = 0;
    // Set the first and last to null (queue is empty)
    queue->first = queue->last = NULL;
    // Return the new queue created
    return queue;
}

// ***** Is Empty *****
int isEmpty(struct LinkedQueue *queue)
{
    return queue->size == 0;
}

int size(struct LinkedQueue *queue)
{
    return queue->size;
}

// ***** Enqueue *****
void enqueue(struct LinkedQueue *queue, void *data)
{
    // Malloc for the new Node to enqueue
    struct Node *nNode = malloc(sizeof(struct Node));
    if (nNode == NULL)
    {
        fprintf(stderr, "Malloc failed...\n");
        exit(1);
    }
    // New Node data and next
    nNode->data = data;
    nNode->next = NULL;
    // Check if the queue is empty
    if (isEmpty(queue))
    {
        // Insert new Node at first and at last
        queue->first = queue->last = nNode;
    }
    else
    {
        // Enqueue new Node at last
        queue->last->next = nNode;
        // Mode last pointer
        queue->last = nNode;
    }
    // Update the size
    queue->size++;
}

// ***** Peek *****
void *peek(struct LinkedQueue *queue)
{
    if (isEmpty(queue))
    {
        fprintf(stderr, "Queue is empty !\n");
        exit(2);
    }
    void *data = queue->first->data;
    return data;
}

// ***** Dequeue *****
void *dequeue(struct LinkedQueue *queue)
{
    if (isEmpty(queue))
    {
        fprintf(stderr, "Queue is empty !\n");
        exit(2);
    }
    // Save first struct Node pointer
    struct Node *temp = queue->first;
    // Save Data from first struct Node as temp
    void *data = temp->data;
    // Move pointers
    queue->first = queue->first->next;
    // Free temp (old first struct Node)
    free(temp);
    // Adjust size
    queue->size--;
    // Return data
    return data;
}

// ***** Main *****
int main(int argc, char const *argv[])
{
    printf("\n");

    // Example usage
    struct LinkedQueue *queue = createLinkedQueue(10);

    // Is empty test : Should be 1 for true
    printf("Queue is empty ? %d\n", isEmpty(queue));

    // Enqueue test
    printf("Enqueuing 1, 2, 3...\n");
    int a = 1;
    int b = 2;
    int c = 3;
    enqueue(queue, &a);
    enqueue(queue, &b);
    enqueue(queue, &c);

    // Is Empty test : Should be 0 for false
    printf("Queue is empty ? %d\n", isEmpty(queue));

    // Size test : Should be 3
    printf("Size of the queue: %d\n", size(queue));

    // Print first : Should be 1
    int *first = queue->first->data;
    printf("\tfirst data = %d\n", *first);

    // Print second : Sould be 2
    int *second = queue->first->next->data;
    printf("\tsecond data = %d\n", *second);

    // Print last : Should be 3
    int *last = queue->last->data;
    printf("\tlast data = %d\n", *last);

    // Peek test : Should be 1
    int *peekData = peek(queue);
    printf("peek data = %d\n", *peekData);

    // Dequeue test : Should be 1
    int *dequeueData = dequeue(queue);
    printf("dequeue data = %d\n", *dequeueData);

    // Size test : Should be 2
    printf("Size of the queue: %d\n", size(queue));

    // Peek test : Should be 2 (1 was removed)
    peekData = peek(queue);
    printf("peek data = %d\n", *peekData);

    // Dequeue test : Should be 2
    dequeueData = dequeue(queue);
    printf("dequeue data = %d\n", *dequeueData);

    // Size test : Should be 1
    printf("Size of the queue: %d\n", size(queue));

    // Peek test : Should be 3 (2 was removed)
    peekData = peek(queue);
    printf("peek data = %d\n", *peekData);

    // Dequeue test : Should be 3
    dequeueData = dequeue(queue);
    printf("dequeue data = %d\n", *dequeueData);

    // Size test : Should be 0
    printf("Size of the queue: %d\n", size(queue));

    // Peek test : Should be stderr and exit(2)
    peekData = peek(queue);
    printf("peek data = %d\n", *peekData);

    /*
    // Iteration test
    struct Node *iterator = queue->first;
    int *iteratorData;
    while (iterator != NULL)
    {
        iteratorData = iterator->data;
        printf("%d\n", *iteratorData);
        iterator = iterator->next;
    }
    */
    return 0;
}
