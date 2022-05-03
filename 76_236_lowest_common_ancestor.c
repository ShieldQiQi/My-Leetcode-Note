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

void dfs(struct TreeNode *root, struct TreeNode* p, struct TreeNode* q, int *p_level, int *q_level, struct TreeNode **p_array, struct TreeNode **q_array, int level)
{
    if (*p_level == -1) {
        p_array[level] = root;
    }
    if (root == p)
        *p_level = level;

    if (*q_level == -1) {
        q_array[level] = root;
    }
    if (root == q)
        *q_level = level;

    if ((*p_level == -1 || *q_level == -1) && root->left)
        dfs(root->left, p, q, p_level, q_level, p_array, q_array, level+1);
    if ((*p_level == -1 || *q_level == -1) && root->right)
        dfs(root->right, p, q, p_level, q_level, p_array, q_array, level+1);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    int p_level = -1, q_level = -1;
    struct TreeNode **p_array = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*50000);
    struct TreeNode **q_array = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*50000);
    
    dfs(root, p, q, &p_level, &q_level, p_array, q_array, 0);
    int level = p_level>q_level?q_level:p_level;
    for (int i=level; i>=0; i--) {
        if (p_array[i] == q_array[i])
            return p_array[i];
    }
    return NULL;
}

int main()
{
    struct TreeNode left = {-10, NULL, NULL};
    struct TreeNode right = {10, NULL, NULL};
    struct TreeNode root = {0, &left, &right};

    struct TreeNode *ans = lowestCommonAncestor(&root, &left, &right);
    printf("%d", ans->val);

    return 0;
}