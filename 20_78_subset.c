#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** returnArray, int index, int start, int count, int* temp)
{
    if(index==count)
    {
        int* subset = (int*)malloc(count*sizeof(int));
        for(int j=0; j<count; j++) {
            subset[j] = temp[j];
        }
        (*returnColumnSizes)[*returnSize] = count;
        returnArray[*returnSize] = subset;
        (*returnSize)++;
        return;
    }
    for(int i=start; i<numsSize; i++)
    {
        temp[index] = nums[i];
        dfs(nums, numsSize, returnSize, returnColumnSizes, returnArray, index+1, i+1, count, temp);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int** returnArray = (int**)malloc(40000*sizeof(int*));
    *returnColumnSizes = (int*)malloc(40000*sizeof(int));
    *returnSize = 0;

    for(int count=0; count<=numsSize; count++)
    {
        int* temp = (int*)malloc(count*sizeof(int));
        dfs(nums, numsSize, returnSize, returnColumnSizes, returnArray, 0, 0, count, temp);
        free(temp);
    }
    return returnArray;
}
int main()
{
    int nums[4] = {3, 2, 4, 1};
    int numsSize = 4;
    int returnSize;
    int* returnColumnSizes;

    int** returnArray = subsets(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("[");
    for(int i=0; i<returnSize; i++)
    {
        printf("[");
        for(int j=0; j<returnColumnSizes[i]; j++)
            printf("%d,",returnArray[i][j]);
        printf("],");
    }
    printf("]");

    return 0;
}