// 哈希法
// 排序后取中位数
// 对拼消耗法
#include <stdio.h>

int majorityElement(int* nums, int numsSize){
    int majorNum = nums[0];
    int count = 1;
    for(int i=1; i<numsSize; i++)
    {
        if(count == 0)
            majorNum = nums[i];
        if(majorNum==nums[i])
        {
            count++;
        } else {
            count--;
        }
    }
    return majorNum;
}

int main()
{
    int nums[7] = {2,2,1,1,1,2,2};

    int majorityNum = majorityElement(nums, 7);
    printf("majorityNum Number is %d\n", majorityNum);

    return 0;
}