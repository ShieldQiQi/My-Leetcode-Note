#include <stdio.h>
#include <stdlib.h>

struct dataItem {
    int key;
    int value;
    struct dataItem* next;
};

inline int hashCode(int key, int size) {return abs(key) % size;};

int hash_sc_searchNode(int key, struct dataItem** hashArray, int size)
{
    int hashIndex = hashCode(key, size);
    struct dataItem* temp = hashArray[hashIndex];
    while(temp != NULL)
    {
        if(temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return NULL;
}

// insert Item operation
int hash_sc_insertNode(int key, int value, struct dataItem** hashArray, int size)
{
    int hashIndex = hashCode(key, size);
    if(hashArray[hashIndex]==NULL)
    {
        hashArray[hashIndex] = (struct dataItem*)malloc(sizeof(struct dataItem));
        hashArray[hashIndex]->key = key;
        hashArray[hashIndex]->value = value;
        hashArray[hashIndex]->next = NULL;
        return 1;
    }

    struct dataItem* temp = hashArray[hashIndex];
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (struct dataItem*)malloc(sizeof(struct dataItem));
    temp->next->key = key;
    temp->next->value = value;
    temp->next->next = NULL;
    return 1;
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traceBack(int treeIndex, int* begin, int* preorder, int* inorder, int inorderSize, struct TreeNode* root, int lpreIndex, int rpreIndex, int rootIndex, struct dataItem** hashArray)
{
    while((*begin)<inorderSize)
    {
        int currentIndex = hash_sc_searchNode(preorder[*begin], hashArray, inorderSize);
        if(currentIndex<rootIndex && (currentIndex>lpreIndex || (lpreIndex==treeIndex)))
        {
            // find the first left child-tree
            struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            *temp = (struct TreeNode){preorder[*begin], NULL, NULL};
            root->left = temp;
            printf("root %d add left child %d\n", root->val, temp->val);
            (*begin)++;
            traceBack(treeIndex, begin, preorder, inorder, inorderSize, temp, lpreIndex, rootIndex, currentIndex, hashArray);
            if((*begin)<inorderSize)
                currentIndex = hash_sc_searchNode(preorder[*begin], hashArray, inorderSize);
        }
        if((*begin)<inorderSize && currentIndex>rootIndex && (currentIndex<rpreIndex || (treeIndex==rpreIndex)))
        {
            // find the first right child-tree
            struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            *temp = (struct TreeNode){preorder[*begin], NULL, NULL};
            root->right = temp;
            printf("root %d add right child %d\n", root->val, temp->val);
            (*begin)++;
            traceBack(treeIndex, begin, preorder, inorder, inorderSize, temp, rootIndex, rpreIndex, currentIndex, hashArray);
        }
        return;
    }
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    // use hash table to store the inorder array
    struct dataItem** hashArray = (struct dataItem**)malloc(sizeof(struct dataItem*)*inorderSize);
    for(int i=0; i<inorderSize; i++)
        hashArray[i] = NULL;
    for(int i=0; i<inorderSize; i++)
        hash_sc_insertNode(inorder[i], i, hashArray, inorderSize);
    // get the tree-root
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = preorder[0];
    int rootIndex = hash_sc_searchNode(preorder[0], hashArray, inorderSize);

    int begin = 1;
    traceBack(-1, &begin, preorder, inorder, inorderSize, root, -1, -1, rootIndex, hashArray);

    return root;
}

int main()
{
    const int size = 4;
    // int preOrder[5] = {3,9,20,15,7};
    // int inOrder[5] = {9,3,15,20,7};
    int preOrder[size] = {3,1,2,4};
    int inOrder[size] = {1,2,3,4};
    
    
    struct TreeNode* treeRoot =  buildTree(preOrder, size, inOrder, size);

    // printf the tree



    return 0;
}