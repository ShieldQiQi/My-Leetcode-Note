#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void bfs(struct Queue *candidate, int **ans, int *returnSize, int** returnColumnSizes)
{
    (*returnColumnSizes)[*returnSize] = 0;
    int *level = (int*)malloc(sizeof(int)*500);
    int size = candidate->size;
    while (size--) {
        struct TreeNode *tmp = popQueue(candidate);
        level[(*returnColumnSizes)[*returnSize]] = tmp->val;
        (*returnColumnSizes)[*returnSize] += 1;
        if (tmp->left)
            insertQueue(candidate, tmp->left);
        if (tmp->right)
            insertQueue(candidate, tmp->right);
    }
    ans[*returnSize] = level;
    *returnSize += 1;
    if (candidate->size)
        bfs(candidate, ans, returnSize, returnColumnSizes);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int)*2000);
    int **ans = (int**)malloc(sizeof(int*)*2000);
    if (root) {
        struct Queue *queue = initQueue(&root, 1);
        bfs(queue, ans, returnSize, returnColumnSizes);
    }

    return ans;
}

int main()
{
    struct TreeNode left = {-10, NULL, NULL};
    struct TreeNode right = {10, NULL, NULL};
    struct TreeNode root = {0, &left, &right};

    int returnSize, *returnColumnSizes;
    int **ans = levelOrder(&root, &returnSize, &returnColumnSizes);

    for (int i=0; i<returnSize; i++) {
        for (int j=0; j<returnColumnSizes[i]; j++) {
            printf("%d ", ans[i][j]);
        }
    }

    return 0;
}