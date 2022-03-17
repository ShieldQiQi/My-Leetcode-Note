/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int* answer = (int*)malloc(sizeof(int)*numsSize);

    answer[0] = nums[0];
    for(int i=1; i<numsSize-1; i++)
    {
        answer[i] = nums[i]*answer[i-1];
    }

    answer[numsSize-1] = answer[numsSize-2];
    for(int i=numsSize-2; i>0; i--)
    {
        answer[i] = answer[i-1]*nums[i+1];
        nums[i] = nums[i]*nums[i+1];
    }
    answer[0] = nums[1];

    *returnSize = numsSize;
    return answer;
}


int main()
{
    const int numsSize = 4;
    int nums[4] = {1, 2, 3, 4};
    int returnSize;
    int* ans = productExceptSelf(nums, numsSize, &returnSize);

    for(int i=0; i<returnSize; i++)
        printf("%d ", ans[i]);

    return 0;
}