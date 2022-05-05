#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode *root, int *sum)
{
    if (!root)
        return;
    dfs(root->right, sum);
    *sum += root->val;
    root->val = *sum;
    dfs(root->left, sum);
}

struct TreeNode* convertBST(struct TreeNode* root)
{
    int sum = 0;
    dfs(root, &sum);

    return root;
}

int main()
{
    struct TreeNode left = {-10, NULL, NULL};
    struct TreeNode right = {10, NULL, NULL};
    struct TreeNode root = {2, &left, &right};

    convertBST(&root);

    return 0;
}