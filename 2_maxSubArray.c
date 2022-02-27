#include <stdlib.h>
#include <stdio.h>

int maxSubArray(int* nums, int numsSize)
{
    int maxSum = nums[0];
    int preMax = nums[0];

    for(int i = 1; i<numsSize; i++)
    {
        if(nums[i]<nums[i]+preMax)
        {
            preMax += nums[i];
        } else {
            preMax = nums[i];
        }
        maxSum = maxSum>preMax?maxSum:preMax;
    }
    return maxSum;
}

int main()
{
    int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int nums2[5] = {5,4,-1,7,8};
    printf("%d\n", maxSubArray(nums2, 5));
    return 0;
}