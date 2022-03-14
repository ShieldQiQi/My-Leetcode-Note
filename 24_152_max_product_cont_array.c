#include <stdio.h>
#include <stdlib.h>

int maxProduct(int* nums, int numsSize)
{
    int maxResult = nums[0];

    int begin = 0;
    while(begin<numsSize)
    {
        if(nums[begin]==0)
        {
            begin++;
            if(maxResult < 0)
                maxResult = 0;
            continue;
        }
        int temp = 1;
        int firstNegIndex = -1;
        int lastNegIndex = -1;
        int forward = 1;
        int backward = 1;
        int count = 0;
        while(begin<numsSize && nums[begin] != 0)
        {
            if(firstNegIndex==-1)
            {
                if(nums[begin]<0)
                    firstNegIndex = begin;
                forward = forward*nums[begin];
            }
            if(nums[begin]<0) {
                lastNegIndex = begin;
                backward = nums[begin];
            } else {
                backward = backward*nums[begin];
            }
            temp = temp*nums[begin];
            begin++;
            count++;
        }
        if(temp<0 && count>1)
        {
            if(forward>backward)
                temp = temp/forward;
            else
                temp = temp/backward;
        }
        if(maxResult < temp)
            maxResult = temp;
    }

    return maxResult;
}

int main()
{
    const int numsSize = 6;
    int nums[numsSize] = {-2, 0, -3, -30, 0, 100};
    int max_product = maxProduct(nums, numsSize);

    printf("max product is %d\n", max_product);

    return 0;
}