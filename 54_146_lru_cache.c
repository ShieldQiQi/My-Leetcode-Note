#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

// define the LRU data structure

struct cacheNode {
    int key;
    int value;
    struct cacheNode *pre;
    struct cacheNode *next;
};
typedef struct {
    int capacity;
    int count;
    struct cacheNode *head;
    struct cacheNode *tail;
} LRUCache;

struct dataItem **hashTable;

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache *cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->count = 0;
    cache->head = NULL;
    cache->tail = NULL;
    // init hashTable
    hashTable = (struct dataItem**)malloc(sizeof(struct dataItem*)*capacity);
    for(int i=0; i<capacity; i++)
        hashTable[i] = NULL;
    return cache;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    struct dataItem* temp = hash_sc_searchNode(key, hashTable, obj->capacity);
    if(temp != NULL)
    {
        struct cacheNode *node = (struct cacheNode*)(temp->value);
        if(node != obj->head)
        {
            if(node == obj->tail)
                obj->tail = node->pre;
            else
                node->next->pre = node->pre;
            node->pre->next = node->next;
            node->next = obj->head;
            obj->head->pre = node;
            node->pre = NULL;
            obj->head = node;
        }
        return ((struct cacheNode*)(temp->value))->value;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    if(obj == NULL)
        return;
    struct dataItem* temp = hash_sc_searchNode(key, hashTable, obj->capacity);
    if(temp != NULL)
    {
        struct cacheNode *node = (struct cacheNode*)(temp->value);
        node->value = value;
        if(node != obj->head)
        {
            if(node == obj->tail)
                obj->tail = node->pre;
            else
                node->next->pre = node->pre;
            node->pre->next = node->next;
            node->next = obj->head;
            obj->head->pre = node;
            node->pre = NULL;
            obj->head = node;
        }
    } else {
        if(obj->count == obj->capacity)
        {
            struct cacheNode *deleteCacheNode = obj->tail;
            obj->tail = obj->tail->pre;
            if(obj->tail == NULL)
                obj->head = NULL;
            else
                obj->tail->next = NULL;
            struct dataItem* deleteNode = hash_sc_searchNode(deleteCacheNode->key, hashTable, obj->capacity);
            free(hash_sc_deleteNode(deleteNode, hashTable, obj->capacity));
            free(deleteCacheNode);
            obj->count -= 1;
        }
        struct cacheNode *newNode = (struct cacheNode*)malloc(sizeof(struct cacheNode));
        newNode->key = key;
        newNode->value = value;
        newNode->pre = NULL;
        newNode->next = obj->head;
        if(obj->head != NULL)
            obj->head->pre = newNode;
        obj->head = newNode;
        obj->count += 1;
        if(obj->tail == NULL)
            obj->tail = obj->head;
        hash_sc_insertNode(key, (unsigned long long)newNode, hashTable, obj->capacity);
    }
}

void lRUCacheFree(LRUCache* obj)
{
    struct cacheNode *temp = obj->head;
    while(temp != NULL)
    {
        struct dataItem* deleteNode = hash_sc_searchNode(temp->key, hashTable, obj->capacity);
        free(hash_sc_deleteNode(deleteNode, hashTable, obj->capacity));
        if(temp->next == NULL)
        {
            free(temp);
            break;
        } else {
            temp = temp->next;
            free(temp->pre);
        }
    }
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

int main()
{
    LRUCache *cache = lRUCacheCreate(2);
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    printf("%d ", lRUCacheGet(cache, 1));
    lRUCachePut(cache, 3, 3);
    printf("%d ", lRUCacheGet(cache, 2));
    lRUCachePut(cache, 4, 4);
    printf("%d ", lRUCacheGet(cache, 1));
    printf("%d ", lRUCacheGet(cache, 3));
    printf("%d ", lRUCacheGet(cache, 4));
    lRUCacheFree(cache);

    return 0;
}