#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int)*temperaturesSize);
    *returnSize = temperaturesSize;

    // [0] 单调栈 O(n)解法
    struct Stack* stack = initStack();
    for(int i=0; i<temperaturesSize;)
    {
        if(stack->count==0 || temperatures[i]<=temperatures[stack->next->value])
        {
            pushStack(stack, i);
            ++i;
        } else {
            int index = popStack(stack);
            ans[index] = i-index;
        }
    }
    while(stack->count)
    {
        int index = popStack(stack);
        ans[index] = 0;
    }
    
    // [1] 暴力搜索

    // for(int i=0; i<temperaturesSize; i++)
    // {
    //     int j = 1;
    //     while(i+j<temperaturesSize && temperatures[i+j]<=temperatures[i]) {
    //         ++j;
    //     }
    //     if(i+j<temperaturesSize)
    //         ans[i] = j;
    //     else
    //         ans[i] = 0;
    // }

    // [2] 暴力优化

    // int* next = (int*)malloc(sizeof(int)*101);
    // for(int i=0; i<101; i++)
    //     next[i] = INT_MAX;
    // for(int i=temperaturesSize-1; i>=0; i--)
    // {
    //     int warmerIndex = INT_MAX;
    //     for(int j=temperatures[i]+1; j<=100; j++)
    //     {
    //         warmerIndex = fmin(next[j], warmerIndex);
    //     }
    //     if(warmerIndex != INT_MAX)
    //         ans[i] = warmerIndex-i;
    //     else
    //         ans[i] = 0;
    //     next[temperatures[i]] = i;
    // }

    return ans;
}


int main()
{
    int temperatures[8] = {73,74,75,71,69,72,76,73};
    int returnSize;
    int* ans = dailyTemperatures(temperatures, 8, &returnSize);

    for(int i=0; i<returnSize; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}