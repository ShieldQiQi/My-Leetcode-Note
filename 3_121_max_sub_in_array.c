/*
 * max sub in array by order
 * Author: XiaoFang Qi
 * Date: 2022/2/27
 */

#include <stdio.h>
#include <stdlib.h>

// O(n)遍历每一个数组元素，同时记录已遍历元素中最小的数，从而可得最大的差值
int maxProfit(int* prices, int pricesSize){
    int maxSub = 0, minElement = prices[0];
    for(int i = 1; i<pricesSize; i++)
    {
        if(prices[i]>minElement)
        {
            if(maxSub<prices[i]-minElement)
            {
                maxSub = prices[i]-minElement;
            }
        } else {
            minElement = prices[i];
        }
    }
    return maxSub;
}

int main()
{
    int prices[6] = {7, 1, 5, 3, 6, 4};
    int theMaxProfit = maxProfit(prices, 6);
    printf("the max profit is %d\n", theMaxProfit);

    return 0;
}