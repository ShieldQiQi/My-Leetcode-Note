#ifndef LINKEDLIST_C_
#define LINKEDLIST_C_

struct listNode {
    int data[2];
    struct listNode* next;
};

struct listHead {
    int listCount;
    struct listNode* next;
};

// init
struct listHead* initLinkedList();
// insert
void insertLinkedList(struct listHead* linkedList, int *data, int dataColSize, int index);
// travel
int** travelLinkedList(struct listHead* linkedList, int dataColSize);

#endif