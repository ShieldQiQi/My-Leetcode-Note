#include <stdio.h>
#include <stdlib.h>


// 方法一: 动态规划
int lengthOfLIS_1(int* nums, int numsSize)
{
    int maxLength = 1;
    int* pre = (int*)malloc(sizeof(int)*numsSize);
    pre[0] = 1;
    for(int i=1; i<numsSize; i++)
    {
        int temp = 1;
        for(int j=0; j<i; j++)
        {
            if(nums[i]>nums[j] && pre[j]+1>temp)
                temp = pre[j] + 1;
        }
        pre[i] = temp;
        if(maxLength<pre[i])
            maxLength = pre[i];
    }

    return maxLength;
}

// 方法二: 二分
int lengthOfLIS_2(int* nums, int numsSize)
{
    int maxLength = 1;
    int* ansNums = (int*)malloc(sizeof(int)*numsSize);
    ansNums[0] = nums[0];
    for(int i=1; i<numsSize; i++)
    {
        int left=0, right=maxLength-1;
        while(left<=right)
        {
            int middle = (left+right)/2;
            if(nums[i]>ansNums[middle])
            {
                left = middle+1;
            } else {
                right = middle-1;
            }
        }
        if(left==maxLength)
        {
            ansNums[maxLength] = nums[i];
            maxLength++;
        } else {
            ansNums[right+1] = nums[i];
        }
    }

    return maxLength;
}

int main()
{
    int nums[8] = {10,9,2,5,3,7,101,18};
    int maxLength = lengthOfLIS_2(nums, 8);

    printf("%d", maxLength);

    return 0;
}