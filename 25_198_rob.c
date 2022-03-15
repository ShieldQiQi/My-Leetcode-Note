#include <stdio.h>
#include <stdlib.h>

void dfs(int* nums, int numsSize, int index, int temp, int* maxRobMoney)
{
    if(index+2<numsSize)
    {
        dfs(nums, numsSize, index+2, temp+nums[index+2], maxRobMoney);
    } else {
        if(*maxRobMoney < temp)
            *maxRobMoney = temp;
        return;
    }

    if(index+3<numsSize)
    {
        if(index==-2 || nums[index+1]<nums[index])
            dfs(nums, numsSize, index+3, temp+nums[index+3], maxRobMoney);
    } else {
        if(*maxRobMoney < temp)
            *maxRobMoney = temp;
        return;
    }
}

int rob(int* nums, int numsSize)
{
    //dfs(nums, numsSize, -2, 0, &maxRobMoney);

    if(numsSize>=2 && nums[1]<nums[0])
        nums[1] = nums[0];

    for(int i=2; i<numsSize; i++)
    {
        if(nums[i]+nums[i-2] > nums[i-1])
        {
            nums[i] = nums[i]+nums[i-2];
        } else {
            nums[i] = nums[i-1];
        }
    }

    return nums[numsSize-1];
}

int main()
{
    const int numsSize = 3;
    int nums[numsSize] = {2,3,2};
    int maxRobMoney = rob(nums, numsSize);

    printf("max rob money is %d\n", maxRobMoney);

    return 0;
}