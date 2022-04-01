#ifndef STACK_H_
#define STACK_H_

struct Node {
    int value;
    struct Node* next;
};

struct Stack {
    int count;
    struct Node* next;
};

struct Stack* initStack();

int popStack(struct Stack* stack);

void pushStack(struct Stack* stack, int value);

#endif