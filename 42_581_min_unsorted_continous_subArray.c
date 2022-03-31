#include <stdio.h>
#include <stdlib.h>

int findUnsortedSubarray(int* nums, int numsSize)
{
    if(numsSize==1)
        return 0;

    int left = 0, right = numsSize-1;
    int max = nums[0];
    int min = nums[numsSize-1];

    for(int i=0, j=numsSize-1; i<numsSize && j>=0; i++, j--)
    {
        if(nums[i]<max)
            left = i;
        max = nums[i]>max?nums[i]:max;
        if(nums[j]>min)
            right = j;
        min = nums[j]<min?nums[j]:min;
    }

    return left-right+1>1?left-right+1:0;
}

int main()
{
    int nums[7] = {2,6,4,8,10,9,15};

    int ans = findUnsortedSubarray(nums, 7);
    printf("%d", ans);

    return 0;
}