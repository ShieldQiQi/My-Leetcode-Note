#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 位运算

// int* countBits(int n, int* returnSize)
// {
//     int *ans = (int*)malloc(sizeof(int)*(n+1));
//     *returnSize = n+1;
//     for (int i=0; i<=n; i++) {
//         ans[i] = 0;
//         for (int j=0; j<31; j++) {
//             int mask = 1 << j;
//             if (i & mask)
//                 ans[i]++;
//         }
//     }
//     return ans;
// }

// 动态规划

int* countBits(int n, int* returnSize)
{
    int *ans = (int*)malloc(sizeof(int)*(n+1));
    *returnSize = n + 1;
    ans[0] = 0;
    for (int i=1; i<=n; i++) {
        if (i%2) {
            ans[i] = ans[i-1] + 1;
        } else {
            ans[i] = ans[i/2];
        }
    }

    return ans;
}

int main()
{
    int returnSize;
    int *ans = countBits(10, &returnSize);
    for (int i=0; i<returnSize; i++)
        printf("%d ", ans[i]);

    return 0;
}
