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

int dfs(struct TreeNode *root, int *diam)
{
    if(root == NULL)
        return 0;
    int left_depth = dfs(root->left, diam) + (root->left!=NULL);
    int right_depth = dfs(root->right, diam) + (root->right!=NULL);
    int current_diam = left_depth + right_depth;
    if(*diam < current_diam)
        *diam = current_diam;
    return left_depth > right_depth? left_depth:right_depth;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int diam = 0;
    dfs(root, &diam);

    return diam;
}

int main()
{
    struct TreeNode root, left_child, right_child;
    root.left = &left_child;
    left_child.left = left_child.right = NULL;
    right_child.left = right_child.right = NULL;
    root.right = &right_child;
    root.val = 0;
    left_child.val = 1;
    right_child.val = 2;

    printf("%d", diameterOfBinaryTree(&root));

    return 0;
}