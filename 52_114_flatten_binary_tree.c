#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode *root, struct TreeNode **ans)
{
    if(root->left != NULL)
    {
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val = root->left->val;
        temp->left = NULL;
        temp->right = NULL;
        (*ans)->right = temp;
        (*ans) = (*ans)->right;
        dfs(root->left, ans);
    }
    if(root->right != NULL)
    {
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val = root->right->val;
        temp->left = NULL;
        temp->right = NULL;
        (*ans)->right = temp;
        (*ans) = (*ans)->right;
        dfs(root->right, ans);
    }
}

void flatten(struct TreeNode* root)
{
    struct TreeNode* ans = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    ans->left = NULL;
    ans->right = NULL;
    struct TreeNode* ansTemp = ans;
    struct TreeNode** ansPtr = &ans;
    if(root != NULL)
    {
        dfs(root, ansPtr);
        root->left = NULL;
        root->right = ansTemp->right;
    }
}

int main()
{
    struct TreeNode root = {6, NULL, NULL};
    struct TreeNode left = {2, NULL, NULL};
    struct TreeNode right = {3, NULL, NULL};
    root.left = &left;
    root.right = &right;

    flatten(&root);
    struct TreeNode *temp = &root;
    while(temp)
    {
        printf("%d ", temp->val);
        temp = temp->right;
    }

    return 0;
}