#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>

int canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    int count = numCourses;
    struct Queue *queue = initQueue(NULL, 0);
    int *in = (int*)malloc(sizeof(int)*numCourses);
    int *edge_num = (int*)malloc(sizeof(int)*numCourses);
    int (*edge)[5000] = (int(*)[5000])malloc(sizeof(int)*numCourses*5000);
    memset(in, 0, numCourses*sizeof(int));
    memset(edge_num, 0, numCourses*sizeof(int));

    for (int i=0; i<prerequisitesSize; i++) {
        in[prerequisites[i][1]]++;
        edge[prerequisites[i][0]][edge_num[prerequisites[i][0]]] = prerequisites[i][1];
        edge_num[prerequisites[i][0]]++;
    }
    for (int i=0; i<numCourses; i++)
        if (!in[i])
            insertQueue(queue, i);
    while (queue->size) {
        count--;
        int node = popQueue(queue);
        for (int i=0; i<edge_num[node]; i++) {
            in[edge[node][i]]--;
            if (!in[edge[node][i]])
                insertQueue(queue, edge[node][i]);
        }
    }
    if (count)
        return 0;
    return 1;
}

int main()
{
    int pre1[2] = {1, 0};
    int pre2[2] = {0, 1};
    int *prerequisites[2] = {pre1, pre2};
    int *prerequisitesColSize = (int*)malloc(sizeof(int)*2);
    printf("%d", canFinish(2, prerequisites, 2, prerequisitesColSize));
    return 0;
}