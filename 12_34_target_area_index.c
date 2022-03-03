#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int left = 0, right = numsSize-1;

    *returnSize = 2;
    int* returnIndex = (int*)malloc(2*sizeof(int));
    returnIndex[0] = -1;
    returnIndex[1] = -1;
    
    // find the start index
    while(left < right)
    {
        int middleIndex = (left+right)/2;
        if(nums[middleIndex] < target)
        {
            if(nums[middleIndex+1]==target)
            {
                returnIndex[0] = middleIndex+1;
                break;
            } else {
                left = middleIndex+1;
                continue;
            }
        }
        right = middleIndex;
    }
    if(left==right && nums[left]==target)
        returnIndex[0] = left;
    //find the end index
    left = 0;
    right = numsSize-1;
    while(returnIndex[0]!=-1 && left < right)
    {
        int middleIndex = ceil((left+right)/2.0);
        if(nums[middleIndex] > target)
        {
            if(nums[middleIndex-1]==target)
            {
                returnIndex[1] = middleIndex-1;
                break;
            } else {
                right = middleIndex-1;
                continue;
            }
        }
        left = middleIndex;
    }
    if(left==right && nums[left]==target)
        returnIndex[1] = left;
    return returnIndex;
}

int main()
{

    int nums[7] = {0, 0, 1, 2, 3, 3, 4};
    int numsSize = 7;
    int target = 2;
    int returnSize;

    int* index = searchRange(nums, numsSize, target, &returnSize);

    printf("%d %d \n", index[0], index[1]);

    return 0;
}