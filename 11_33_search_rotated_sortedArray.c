#include <math.h>
#include <stdio.h>

int findRotateIndex(int* nums, int left, int right, int n)
{
    int middleIndex = floor((left+right)/2);
    
    if(left == right || (nums[middleIndex]>n && n>=nums[middleIndex+1]))
    {
        return middleIndex;
    } else if(nums[middleIndex]>n) {
        findRotateIndex(nums, middleIndex+1, right, n);
    } else {
        findRotateIndex(nums, left, middleIndex, n);
    }
}

int dichotomy(int* nums, int low, int high, int key)
{
    if(low>high || (low==high && nums[low]!=key))
        return -1;
    int middleIndex = floor((low+high)/2.0);

    if(nums[middleIndex] == key)
    {
        return middleIndex;
    } else if(nums[middleIndex] < key) {
        dichotomy(nums, middleIndex+1, high, key);
    } else {
        dichotomy(nums, low, middleIndex-1, key);
    }
}

int search(int* nums, int numsSize, int target)
{
    int endIndex = findRotateIndex(nums, 0, numsSize-1, nums[numsSize-1]);
    printf("endIndex is %d\n", endIndex);
    
    int index = dichotomy(nums, 0, endIndex, target);
    if(index == -1 && endIndex <= numsSize-1)
        index = dichotomy(nums, endIndex+1, numsSize-1, target);
    return index;
}

int main()
{
    int nums[2] = {3, 1};
    int numsSize = 2;

    int index = search(nums, numsSize, 1);
    printf("target index is %d\n", index);
}