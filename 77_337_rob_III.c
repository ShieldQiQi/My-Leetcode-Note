#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* root, int *pre_2_num, int *pre_1_num)
{
    if (!root) {
        *pre_2_num = 0;
        *pre_1_num = 0;
        return;
    }
    int pre_2_num_l = 0, pre_1_num_l = 0, pre_2_num_r = 0, pre_1_num_r = 0;
    dfs(root->left, &pre_2_num_l, &pre_1_num_l);
    dfs(root->right, &pre_2_num_r, &pre_1_num_r);

    *pre_2_num = pre_1_num_l + pre_1_num_r;
    *pre_1_num = (pre_2_num_l + pre_2_num_r + root->val)>(*pre_2_num)?(pre_2_num_l + pre_2_num_r + root->val):(*pre_2_num);
}

int rob(struct TreeNode* root)
{
    int pre_2_num, pre_1_num;
    dfs(root, &pre_2_num, &pre_1_num);

    return pre_2_num>pre_1_num?pre_2_num:pre_1_num;
}

int main()
{
    struct TreeNode left = {-10, NULL, NULL};
    struct TreeNode right = {10, NULL, NULL};
    struct TreeNode root = {2, &left, &right};

    printf("%d", rob(&root));

    return 0;
}