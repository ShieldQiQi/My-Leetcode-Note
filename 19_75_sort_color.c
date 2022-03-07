#include <stdio.h>
#include <stdlib.h>

void sortColors(int* nums, int numsSize)
{
    int zeroIndex=0;
    int twoIndex = numsSize-1;
    for(int i=0; i<=twoIndex; i++)
    {
        while(nums[i] != 1)
        {
            if(nums[i]==0)
            {
                while(zeroIndex<=twoIndex && nums[zeroIndex]==0)
                    zeroIndex++;
                if(zeroIndex>=i)
                {
                    i = zeroIndex;
                } else {
                    nums[i] = nums[zeroIndex];
                    nums[zeroIndex] = 0;
                    zeroIndex++;
                }
            }
            if(i>numsSize-1)
                break;
            if(nums[i]==2)
            {
                while(twoIndex>=zeroIndex && nums[twoIndex]==2)
                    twoIndex--;
                if(twoIndex>i)
                {
                    nums[i] = nums[twoIndex];
                    nums[twoIndex--] = 2;
                }
            }
            if(twoIndex<i)
                break;
        }
    }
}

int main()
{
    int nums[6] = {2,0,2,1,1,0};
    sortColors(nums, 6);

    for(int i=0; i<6; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}