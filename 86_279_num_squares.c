#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.h"

void bfs(int n, struct Queue *queue, int *layer)
{
    *layer += 1;
    int count = (queue->size)/2;
    while (count) {
        count--;
        int max = popQueue(queue);
        int sum = popQueue(queue);
        for (int i = max; i>=1; i--) {
            int new_sum = sum + i*i;
            if (new_sum == n) {
                return;
            } else if (new_sum < n) {
                insertQueue(queue, i);
                insertQueue(queue, new_sum);
            }
        }
    }
    bfs(n, queue, layer);
}

int numSquares(int n)
{
    int max = floor(sqrt(n));

// BFS剪枝

    // int layer = 0;
    // struct Queue *queue = initQueue(NULL, 0);
    // insertQueue(queue, max);
    // insertQueue(queue, 0);
    // bfs(n, queue, &layer);

// 动态规划
    int *dp = (int*)malloc(sizeof(int)*(n+1));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int min = INT_MAX;
        int max = floor(sqrt(i));
        for (int j = max; j >= 1; j--) {
            if (min > dp[i-j*j])
                min = dp[i-j*j];
        }
        dp[i] = 1 + min;
    }

    // return layer;
    return dp[n];
}

int main()
{
    printf("%d", numSquares(18));

    return 0;
}
