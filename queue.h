#ifndef QUEUE_H_
#define QUEUE_H_

struct Node {
    int value;
    struct Node* next;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
    int size;
};

struct Queue* initQueue(int* nums, int size);

void insertQueue(struct Queue* queue, int value);

int popQueue(struct Queue* queue);

#endif