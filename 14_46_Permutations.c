#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "queue.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void traceBack(struct Queue* queue, int begin, int numsSize, int**returnArray, int* combine, int *returnSize, int* returnColumnSizes)
{
    for(int i=begin; i<numsSize; i++)
    {
        combine[begin] = popQueue(queue);
        traceBack(queue, begin+1, numsSize, returnArray, combine, returnSize, returnColumnSizes);
        insertQueue(queue, combine[begin]);
    }
    if(queue->size == 0)
    {
        int* temp = (int*)malloc(sizeof(int)*numsSize);
        memcpy(temp, combine, sizeof(int)*numsSize);
        returnArray[*returnSize] = temp;
        returnColumnSizes[*returnSize] = numsSize;
        *returnSize += 1; 
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int** returnArray = (int**)malloc(sizeof(int*)*720);
    *returnColumnSizes = (int*)malloc(sizeof(int)*720);
    int *combine = (int*)malloc(numsSize*sizeof(int));
    *returnSize = 0;

    struct Queue* queue = initQueue(nums, numsSize);
    traceBack(queue, 0, numsSize, returnArray, combine, returnSize, *returnColumnSizes);
    
    return returnArray;
}

int main()
{
    int nums[3] = {1, 2, 3};
    int numsSize = 3;
    int returnSize = 0;
    int* returnColumnSizes;

    int** returnArray = permute(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("[ ");
    for(int i=0; i<returnSize; i++)
    {
        printf("[");
        for(int j=0; j<returnColumnSizes[i]; j++)
        {
            printf("%d ", returnArray[i][j]);
        }
        printf("], ");
    }
    printf(" ]");

    return 0;
}

    // struct Queue* queue = initQueue(nums, 3);
    // int count = queue->size;
    // for(int i=0; i<count; i++)
    // {
    //     printf("%d ", popQueue(queue));
    // }