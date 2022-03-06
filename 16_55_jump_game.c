#include <stdio.h>

#define true 1
#define false 0

int canJump(int* nums, int numsSize)
{
    int preIndex = 0;
    int maxIndex = preIndex;
    while(preIndex+nums[preIndex]<numsSize-1)
    {
        for(int i=preIndex+nums[preIndex]; i>=preIndex+1; i--)
        {
            if(i+nums[i]>maxIndex+nums[maxIndex])
            {
                maxIndex = i;
            }
        }
        if(preIndex==maxIndex)
            return false;
        preIndex = maxIndex;
    }
    return true;
}

int main()
{
    int nums[7] = {3,0,8,2,0,0,1};
    int numsSize = 7;

    if(canJump(nums, numsSize))
        printf("true");
    else
        printf("false");

    return 0;
}

