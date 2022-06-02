#ifndef QUEUE_H_
#define QUEUE_H_

struct Node {
    int value;
    struct Node* next;
};

struct DNode {
    int value;
    struct DNode* pre;
    struct DNode* next;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
    int size;
};

struct DQueue {
    struct DNode* head;
    struct DNode* tail;
    int size;
};

struct Queue* initQueue(int* nums, int size);

void insertQueue(struct Queue* queue, int value);

int popQueue(struct Queue* queue);

struct DQueue* initDQueue(int* nums, int size);

void insertDQueue(struct DQueue* queue, int value);

int popDQueue(struct DQueue* queue);

int popDQueueTail(struct DQueue *queue);

#endif