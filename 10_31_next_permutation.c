#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quick_sort.h"

int dichotomy(int* nums, int low, int high, int key)
{
    int middleIndex = floor((low+high)/2.0);
    if((low+high)%2 != 0 && nums[(low+high+1)/2]>key)
    {
        middleIndex = (low+high+1)/2;
    }

    if(low==middleIndex || (nums[middleIndex]-key>0 && nums[middleIndex]-key<=1))
        return middleIndex;
    if(nums[middleIndex] > key)
    {
        dichotomy(nums, middleIndex, high, key);
    } else {
        dichotomy(nums, low, middleIndex, key);
    }
}

void nextPermutation(int* nums, int numsSize)
{
    for(int j=numsSize-2; j>=0; j--)
    {
        int i = dichotomy(nums, j+1, numsSize-1, nums[j]);
        if(nums[i]>nums[j])
        {
            int swap = nums[j];
            nums[j] = nums[i];
            nums[i] = swap;
            quick_sort(nums, j+1, numsSize-1);
            return;
        }
    }
}

int main()
{
    int nums[3] = {1,5,1};
    int numsSize = 3;
    nextPermutation(nums, numsSize);

    for(int i=0; i<numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
}