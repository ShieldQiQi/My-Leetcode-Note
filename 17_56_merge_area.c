#include <stdio.h>
#include <stdlib.h>

void quick_sort_(int* index, int* array, int low, int high)
{
    if(low >= high) // sort ended
        return;
    int i= low;
    int j= high;
    int key = array[low];
    int indexKey = index[low];

    while(low < high)
    {
        while(array[high]>=key && low<high)
        {
            high--;
        }
        if(key > array[high])
        {
            array[low] = array[high];
            index[low] = index[high];
            low++;
        }
        while(array[low]<=key && low<high)
        {
            low++;
        }
        if(key < array[low])
        {
            array[high] = array[low];
            index[high] = index[low];
            high--;
        }
    }
    array[low] = key;
    index[low] = indexKey;
    quick_sort_(index, array, i, low-1);
    quick_sort_(index, array, low+1, j);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    int** returnArray = (int**)malloc(10000*sizeof(int*));
    *returnColumnSizes = (int*)malloc(10000*sizeof(int));
    *returnSize = 0;
    int begin = 0;

    // sort the area first
    int index[intervalsSize];
    int ele0[intervalsSize];
    for(int i=0; i<intervalsSize; i++)
    {
        ele0[i] = intervals[i][0];
        index[i] = i;
    }
    quick_sort_(index, ele0, 0, intervalsSize-1);

    // merge the area forward
    while(begin<intervalsSize)
    {
        int maxIndex = begin;
        for(int j=begin; j<intervalsSize; j++)
        {
            if(j<intervalsSize-1 && intervals[index[maxIndex]][1]>=intervals[index[j+1]][0])
            {
                if(intervals[index[maxIndex]][1]<=intervals[index[j+1]][1])
                    maxIndex = j+1;
            } else {
                // find a area block
                int* temp = (int*)malloc(*intervalsColSize*sizeof(int));
                temp[0] = intervals[index[begin]][0];
                temp[1] = intervals[index[maxIndex]][1];
                returnArray[*returnSize] = temp;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
                begin = j+1;
                break;
            }
        }
    }
    return returnArray;
}

int main()
{
    int interval1[2] = {1, 3};
    int interval2[2] = {2, 6};
    int interval3[2] = {8, 10};
    int interval4[2] = {15, 18};
    int* intervals[4] = {interval1, interval2, interval3, interval4};
    int intervalsSize = 4;
    int intervalsColSize = 2;
    int returnSize = 0;
    int* returnColumnSizes;

    int** returnArray = merge(intervals, intervalsSize, &intervalsColSize, &returnSize, &returnColumnSizes);

    for(int i=0; i<returnSize; i++)
    {
        printf("[");
        printf("[%d, %d],", returnArray[i][0], returnArray[i][1]);
        printf("]");
    }

    return 0;
}