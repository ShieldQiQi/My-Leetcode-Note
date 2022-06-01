#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void dfs(struct TreeNode *root, int *max_length)
{
    if (!root)
        return;

    dfs(root->left, max_length);
    dfs(root->right, max_length);

    int left_sum = root->left && root->left->val > 0? root->left->val:0;
    int right_sum = root->right && root->right->val > 0? root->right->val:0;
    int current_length = left_sum + right_sum + root->val;
    if (current_length > *max_length)
        *max_length = current_length;
    root->val += fmax(0, fmax(left_sum, right_sum));
}

int maxPathSum(struct TreeNode* root)
{
    int max_length = -INT_MAX;
    dfs(root, &max_length);

    return max_length;
}

int main()
{
    struct TreeNode root = {
        .val = 2, 
        .left = NULL,
        .right = NULL
    };

    printf("%d", maxPathSum(&root));

    return 0;
}