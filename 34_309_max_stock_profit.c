#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize==0)
        return 0;
    
    // f0: 手上持有股票时的最大收益
    // f1: 手上不持有股票且处于冷冻期时的最大收益, 即卖出股票当天
    // f2: 手上不持有股票且不处于冷冻期时的最大收益

    int f0 = -prices[0];
    int f1 = 0;
    int f2 = 0;

    for(int i=1; i<pricesSize; i++)
    {
        int newf0 = max(f0, f2-prices[i]);  // 前一天持有股票或者前一天不处于冷冻期
        int newf1 = f0+prices[i];           // 前一天必然持有股票
        int newf2 = max(f2, f1);            // 前一天刚卖出处于冷冻期或者不持有股票且不处于冷冻期
        f0 = newf0;
        f1 = newf1;
        f2 = newf2;
    }
    return max(f1, f2);
}

int main()
{
    int prices[5] = {1,2,3,0,2};
    int maxProfit_ = maxProfit(prices, 5);
    printf("%d", maxProfit_);

    return 0;
}