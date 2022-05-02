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

#define false 0
#define true 1

int dfs(struct TreeNode* root, int left_bound, int right_bound, int left_change, int right_change)
{
    if (root->left) {
        if (root->left->val<root->val && (root->left->val>left_bound || (root->left->val==left_bound && !left_change))) {
            if (!dfs(root->left, left_bound, root->val, left_change, 1))
                return false;
        } else {
            return false;
        }
    }
    if (root->right) {
        if (root->right->val>root->val && (root->right->val<right_bound || (root->right->val==right_bound && !right_change))) {
            if(!dfs(root->right, root->val, right_bound, 1, right_change))
                return false;
        } else {
            return false;
        }
    }
    return true;
}

int isValidBST(struct TreeNode* root)
{
    return dfs(root, -INT_MAX-1, INT_MAX, 0, 0);
}

int main()
{
    struct TreeNode left = {-10, NULL, NULL};
    struct TreeNode right = {10, NULL, NULL};
    struct TreeNode root = {0, &left, &right};
    printf("%d", isValidBST(&root));
    return 0;
}