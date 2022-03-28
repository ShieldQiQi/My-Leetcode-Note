#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"
#include "linkedList.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    struct listHead* linkedList = initLinkedList();
    //int** returnArray = (int**)malloc(sizeof(int*)*peopleSize);
    *returnColumnSizes = (int*)malloc(sizeof(int)*peopleSize);
    *returnSize = peopleSize;
    quick_sort2(people, 0, peopleSize-1, 1);
    int temp = people[0][1];
    for(int i=0, pre=0; i<peopleSize; i++)
    {
        if(people[i][1] != temp)
        {
            temp = people[i][1];
            quick_sort2(people, pre, i-1, 0);
            pre = i;
        }
        (*returnColumnSizes)[i] = 2;
    }

    // sort
    // insert first data
    insertLinkedList(linkedList, people[0], 2, 0);
    struct listNode* tempNode = linkedList->next;
    int lowLimitIndex = 1;
    temp = people[0][1];
    int insertIndex = 0;
    for(int i=1; i<peopleSize; i++)
    {
        int preCount = 0;
        tempNode = linkedList->next;
        insertIndex = 0;

        if(temp != people[i][1]) {
            temp = people[i][1];
            lowLimitIndex = 0;
        }

        while(1)
        {
            if(preCount==people[i][1]) {
                int max = insertIndex>lowLimitIndex?insertIndex:lowLimitIndex;
                insertLinkedList(linkedList, people[i], 2, max);
                // printf("insert at %d [%d %d]\n", max, people[i][0], people[i][1]);
                lowLimitIndex = max+1;
                break;
            }
            if(tempNode->data[0]>=people[i][0])
                preCount++;
            insertIndex++;

            tempNode = tempNode->next;
        }
    }

    // travel to get the finial answer
    int** returnArray = travelLinkedList(linkedList, 2);

    return returnArray;
}

int main()
{
    int data[6][2] = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};//{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    int* people[6];
    for(int i=0; i<6; i++)
        people[i] = data[i];

    int peopleColSize[6];
    int returnSize;
    int** returnColumnSizes;
    int** ans = reconstructQueue(people, 6, peopleColSize, &returnSize, returnColumnSizes);

    for(int i=0; i<6; i++)
    {
        printf(" [%d %d] ", ans[i][0], ans[i][1]);
    }

    return 0;
}