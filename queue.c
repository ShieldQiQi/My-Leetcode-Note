/**
 *  Linked queue
 *  Date: 2022/3/4
 *  Author: Qi
 */
#include <stdlib.h>
#include "queue.h"

struct Queue* initQueue(int* nums, int size)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = queue->tail = (struct Node*)malloc(sizeof(struct Node));
    for(int i=0; i<size; i++)
    {
        insertQueue(queue, nums[i]);
    }
    queue->size = size;
    return queue;
}

void insertQueue(struct Queue* queue, int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->value = value;
    queue->tail->next = temp;
    queue->tail = temp;
    queue->size++;
}

int popQueue(struct Queue* queue)
{
    if(queue->size > 0)
    {
        struct Node* temp = queue->head->next;
        queue->head->next = queue->head->next->next;
        int value = temp->value;
        free(temp);
        if((queue->size-=1) == 0)
            queue->tail = queue->head;
        return value;
    }
    return -1;
}

struct DQueue* initDQueue(int* nums, int size)
{
    struct DQueue* queue = (struct DQueue*)malloc(sizeof(struct DQueue));
    queue->head = queue->tail = (struct DNode*)malloc(sizeof(struct DNode));
    for(int i=0; i<size; i++)
    {
        insertDQueue(queue, nums[i]);
    }
    queue->size = size;
    return queue;
}

void insertDQueue(struct DQueue* queue, int value)
{
    struct DNode* temp = (struct DNode*)malloc(sizeof(struct DNode));
    temp->next = NULL;
    temp->pre = queue->tail;
    temp->value = value;
    queue->tail->next = temp;
    queue->tail = temp;
    queue->size++;
}

int popDQueue(struct DQueue* queue)
{
    if(queue->size > 0)
    {
        struct DNode* temp = queue->head->next;
        queue->head->next = queue->head->next->next;
        int value = temp->value;
        free(temp);
        if((queue->size-=1) == 0)
            queue->tail = queue->head;
        else
            queue->head->next->pre = queue->head;
        return value;
    }
    return -1;
}

int popDQueueTail(struct DQueue *queue)
{
    if (queue->size) {
        struct DNode* temp = queue->tail;
        int value = temp->value;
        queue->tail = temp->pre;
        queue->tail->next = NULL;
        free(temp);
        queue->size-=1;
        return value;
    }
    return -1;
}