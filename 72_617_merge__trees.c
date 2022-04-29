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

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 && root2) {
        root1->val += root2->val;
        if (root1->left && root2->left)
            mergeTrees(root1->left, root2->left);
        else if (root2->left)
            root1->left = root2->left;
        if (root1->right && root2->right)
            mergeTrees(root1->right, root2->right);
        else if (root2->right)
            root1->right = root2->right;
    } else if (root2) {
        root1 = root2;
    }
    return root1;
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

    mergeTrees(&root, NULL);

    return 0;
}