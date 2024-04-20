#include <stdio.h>
#include <stdlib.h>

// B: Pointer Manipulation
struct stack{
    int data;
    struct stack* prev;
};

// Create Stack with malloc
struct stack* create_stack(){
    return (struct stack*)malloc(sizeof(struct stack));
};

// Swap top element with the previous
// This function takes a double pointer to the top of the stack as an argument,
// which allows us to modify the pointer to the top element itself.
void swap_ptr(struct stack** top){
    struct stack* first = *top; // Dereference the top pointer to access the top element of the stack.
    struct stack* second = first->prev; // Access the element below the top element, which is the second element.

    // Change the 'prev' pointer of what was the top element to point to
    // the element below the second element (third element in the stack or NULL)
    first->prev = second->prev;

    // The second element's 'prev' pointer is now updated to point to
    // the first element, because the second element will become the new top.
    second->prev = first;

    // Update the original top pointer to point to the second element,
    // which is now the top of the stack after the swap.
    *top = second;
};

// Print full stack of exercice B
void print_stack(struct stack* top) {
    printf("Stack contents from top to bottom:\n");
    while (top != NULL) {
        printf("Current stack address : %p\n", top);
        printf("Data : %d\n", top->data);
        top = top->prev;
    }
}

int main()
{
    struct stack* top = NULL;
 
    // Node 1
    struct stack* first = create_stack();
    first->data = 1;
    first->prev = NULL;
    top = first;

    // Node 2
    struct stack* second = create_stack();
    second->data = 2;
    second->prev = first; 
    top = second;

    // Node 3
    struct stack* third = create_stack();
    third->data = 3;
    third->prev = second; 
    top = third;

    // Show the swap working
    print_stack(top);
    swap_ptr(&top);
    print_stack(top);

    return 0;
}