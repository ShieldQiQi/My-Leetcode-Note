#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers_(int* nums, int numsSize, int* returnSize)
{
    int *returns = (int*)malloc(numsSize*sizeof(int));
    for(int i=0; i<numsSize; i++)
        returns[i] = 1;
    *returnSize = 0;
    for(int i=0; i<numsSize; i++)
    {
        returns[nums[i]-1] -= 1;
        if(returns[nums[i]-1]<0)
            (*returnSize)++;
    }

    int *result = (int*)malloc(*returnSize*sizeof(int));
    for(int i=0,j=0; i<numsSize; i++)
    {
        if(returns[i]==1)
        {
            result[j++] = i+1;
        }
    }
    free(returns);
    return result;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[abs(nums[i])-1]<0)
            (*returnSize)++;
        nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
    }

    int * returns = (int *)malloc(*returnSize*sizeof(int));

    for(int i=0,j=0; i<numsSize; i++)
        if(nums[i]>0)
            returns[j++] = i+1;

    return returns;
}

int main()
{
    int nums[8] = {4,3,2,7,8,2,3,1};
    int numsSize = 8;
    int returnSize;
    int *result = findDisappearedNumbers(nums, numsSize, &returnSize);
    for(int i=0; i<returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    free(result);

    return 0;
}