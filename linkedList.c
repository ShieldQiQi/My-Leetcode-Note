#include "linkedList.h"
#include <stdlib.h>

struct listHead* initLinkedList()
{
    struct listHead* head = (struct listHead*)malloc(sizeof(struct listHead));
    head->listCount = 0;
    head->next = NULL;
    return head;
}

void insertLinkedList(struct listHead* linkedList, int *data, int dataColSize, int index)
{
    if(index > linkedList->listCount);
        // return error
    
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    for(int i=0; i<dataColSize; i++)
        newNode->data[i] = data[i];
    if(index!=0 && linkedList->listCount!=0)
    {
        int i=1;
        struct listNode* temp = linkedList->next;
        while(i!=index && temp->next!=NULL) {
            temp = temp->next;
            i++;
        }
        struct listNode* nextNode = temp->next;
        newNode->next = nextNode;
        temp->next = newNode;
    } else {
        linkedList->next = newNode;
        newNode->next = NULL;
    }
    linkedList->listCount += 1;
}


int** travelLinkedList(struct listHead* linkedList, int dataColSize)
{
    int** returnArray = (int**)malloc(sizeof(int*)*linkedList->listCount);
    struct listNode* temp = linkedList->next;
    int count = 0;
    while(temp != NULL)
    {
        int* data = (int*)malloc(sizeof(int)*dataColSize);
        for(int i=0; i<dataColSize; i++)
            data[i] = temp->data[i];
        returnArray[count] = data;
        count++;
        temp = temp->next;
    }
    return returnArray;
}