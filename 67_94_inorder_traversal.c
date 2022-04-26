#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* root, int* returnSize, int *middle_list)
{
    if(root->left) {
        dfs(root->left, returnSize, middle_list);
    }
    middle_list[*returnSize] = root->val;
    *returnSize += 1;
    if(root->right) {
        dfs(root->right, returnSize, middle_list);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *middle_list = (int*)malloc(sizeof(int)*100);
    *returnSize = 0;
    if(root)
        dfs(root, returnSize, middle_list);
    return middle_list;
}

int main()
{
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    struct TreeNode *node2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right = node2;
    node2->right = NULL;
    struct TreeNode *node3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node2->left = node3;
    node2->val = 2;
    node3->val = 3;
    node3->left = NULL;
    node3->right = NULL;
    int returnSize;
    int *inorder_list = inorderTraversal(root, &returnSize);

    for(int i=0; i<returnSize; i++)
        printf("%d ", inorder_list[i]);
        
    return 0;
}