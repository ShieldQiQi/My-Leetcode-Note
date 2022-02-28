#include <stdio.h>

void moveZeroes_(int* nums, int numsSize)
{
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i]==0)
        {
            for(int j=i+1; j<numsSize; j++)
            {
                if(nums[j] != 0)
                {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
                if(j == numsSize-1)
                    return;
            }
        }
    }
}

void moveZeroes(int* nums, int numsSize)
{
    int j = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] != 0)
        {
            nums[j++] = nums[i];
            if(j != i+1)
                nums[i] = 0;
        }
    }
}

int main()
{
    int nums[7] = {0,1,0,3,12,0,0};
    int numsSize = 7;
    moveZeroes(nums, numsSize);
    for(int i=0; i<numsSize; i++)
        printf("%d ", nums[i]);
    return 0;
}