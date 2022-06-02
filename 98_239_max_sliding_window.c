#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    *returnSize = numsSize-k+1;
    struct DQueue *dqueue = initDQueue(NULL, 0);
    int *ans = (int*)malloc(sizeof(int)*(numsSize+1-k));

    for (int i = 0; i < k; i++) {
        while (dqueue->size && nums[dqueue->tail->value] < nums[i])
            popDQueueTail(dqueue);
        insertDQueue(dqueue, i);
    }
    ans[0] = nums[dqueue->head->next->value];
    for (int i = k; i < numsSize; i++) {
        if (nums[i-k] == nums[dqueue->head->next->value])
            popDQueue(dqueue);
        while (dqueue->size && nums[dqueue->tail->value] < nums[i])
            popDQueueTail(dqueue);
        insertDQueue(dqueue, i);
        ans[i-k+1] = nums[dqueue->head->next->value];
    }
    return ans;
}

int main()
{
    int nums[8] = {1,3,-1,-3,5,3,6,7};
    int returnSize = 0;
    
    int *ans = maxSlidingWindow(nums, 8, 3, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", ans[i]);

    return 0;
}