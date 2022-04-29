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
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root == NULL)
        return root;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
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
    struct TreeNode *ans = invertTree(&root);
    
    return 0;
}