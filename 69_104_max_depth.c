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

void dfs(struct TreeNode *root, int *max_depth, int level)
{
    if(root) {
        if (level > *max_depth)
            *max_depth = level;
        dfs(root->left, max_depth, level+1);
        dfs(root->right, max_depth, level+1);
    }
}

int maxDepth(struct TreeNode* root)
{
    int max_depth = 0;
    dfs(root, &max_depth, 1);

    return max_depth;
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
    printf("%d", maxDepth(&root));
    return 0;
}