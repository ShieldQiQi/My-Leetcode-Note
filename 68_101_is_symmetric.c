#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs(struct TreeNode* root_left, struct TreeNode* root_right)
{
    if ((root_left == NULL && root_right != NULL) || 
        (root_left != NULL && root_right == NULL))
        return false;
    if(root_left) {
        if (root_left->left) {
            if(dfs(root_left->left, root_right->right) == false)
                return false;
        } else if (root_right->right != NULL)
            return false;
        if (root_left->val != root_right->val)
            return false;
        if (root_left->right)
            return dfs(root_left->right, root_right->left);
        else if (root_right->left != NULL)
            return false;
    }
    return true;
}

int isSymmetric(struct TreeNode* root)
{
    return dfs(root->left, root->right);
}

int main()
{
    struct TreeNode root, node1, node2, node3, node4, node5, node6;
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.left = NULL;//&node5;
    node2.right = &node6;
    root.val = 1;
    node1.val = 2;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 4;
    node6.val = 3;
    node3.left = node3.right = NULL;
    node4.left = node4.right = NULL;
    node5.left = node5.right = NULL;
    node6.left = node6.right = NULL;
    printf("%d", isSymmetric(&root));

    return 0;
}