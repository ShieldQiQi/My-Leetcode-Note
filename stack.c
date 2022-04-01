#include "stack.h"
#include <stdlib.h>

struct Stack* initStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->count = 0;
    stack->next = NULL;

    return stack;
}

int popStack(struct Stack* stack)
{
    if(stack->count == 0)
        return -1;
    struct Node* tempNode = stack->next;
    int temp = tempNode->value;
    stack->next = stack->next->next;
    free(tempNode);
    stack->count -=1;
    return temp;
}

void pushStack(struct Stack* stack, int value)
{
    struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));
    tempNode->value = value;
    tempNode->next = stack->next;
    stack->next = tempNode;

    stack->count += 1;
}