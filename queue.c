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
        if(queue->size--)
            queue->tail = queue->head;
        return value;
    }
    return -1;
}