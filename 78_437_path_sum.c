#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode *root, struct dataItem** hashTable, int targetSum, int *ans, long long sum)
{
    struct dataItem* tmp;
    if ((tmp = hash_sc_searchNode(sum - targetSum, hashTable, 1000)))
        *ans += tmp->value;
    tmp = hash_sc_searchNode(sum, hashTable, 1000);
    if (tmp)
        tmp->value += 1;
    else
        hash_sc_insertNode(sum, 1, hashTable, 1000);

    if (root->left) {
        dfs(root->left, hashTable, targetSum, ans, sum + root->left->val);
        tmp = hash_sc_searchNode(sum + root->left->val, hashTable, 1000);
        if (tmp->value > 1)
            tmp->value -= 1;
        else
            hash_sc_deleteNode(sum + root->left->val, hashTable, 1000);
    }

    if (root->right) {
        dfs(root->right, hashTable, targetSum, ans, sum + root->right->val);
        tmp = hash_sc_searchNode(sum + root->right->val, hashTable, 1000);
        if (tmp->value > 1)
            tmp->value -= 1;
        else
            hash_sc_deleteNode(sum + root->right->val, hashTable, 1000);
    }
}

int pathSum(struct TreeNode* root, int targetSum)
{
    struct dataItem** hashTable = initHashTable(1000);
    int ans = 0;
    hash_sc_insertNode(0, 1, hashTable, 1000);
    if (root)
        dfs(root, hashTable, targetSum, &ans, root->val);

    return ans;
}

int main()
{
    struct TreeNode left = {-10, NULL, NULL};
    struct TreeNode right = {10, NULL, NULL};
    struct TreeNode root = {2, &left, &right};

    printf("%d", pathSum(&root, -8));

    return 0;
}