/*
给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，为避免会议冲突，同时要考虑充分
利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。

示例 1:
输入: [[0,30],[5,10],[15,20]]
输出: 2

示例 2:
输入: [[7,10],[2,4]]
输出: 1

1 <= intervals.length <= 104
0 <= si < ei <= 10^6
*/
#include <stdio.h>
#include <stdlib.h>

void quick_sort_(int** array, int low, int high);

int minMeetingRooms(int** intervals, int intervalSize, int* intervalColSize)
{
    int minRooms = 0;
    int* end = (int*)malloc(sizeof(int)*10000);
    // sort the intervals by start times
    quick_sort_(intervals, 0, intervalSize-1);

    for(int i=0; i<intervalSize; i++)
    {
        for(int j=0; j<minRooms; j++)
        {
            if(intervals[i][0]>=end[j]) {
                end[j] = intervals[i][1];
                goto founded;
            }
        }
        end[minRooms] = intervals[i][1];
        minRooms++;
founded:;
    }

    return minRooms;
}

int main()
{
    const int intervalSize = 3;
    int testData[intervalSize][2] = {{0,30},{5,10},{15,20}};
    int* intervals[intervalSize] = {testData[0], testData[1], testData[2]};
    int intervalColSize[intervalSize] = {2, 2, 2};

    int minRooms = minMeetingRooms(intervals, intervalSize, intervalColSize);

    printf("need at least %d rooms", minRooms);

    return 0;
}

void quick_sort_(int** array, int low, int high)
{
    if(low >= high) // sort ended
        return;
    int i= low;
    int j= high;
    int key = array[low][0];
    int key_ = array[low][1];

    while(low < high)
    {
        while(array[high][0]>=key && low<high)
        {
            high--;
        }
        if(key > array[high][0])
        {
            array[low][0] = array[high][0];
            array[low][1] = array[high][1];
            low++;
        }
        while(array[low][0]<=key && low<high)
        {
            low++;
        }
        if(key < array[low][0])
        {
            array[high][0] = array[low][0];
            array[high][1] = array[low][1];
            high--;
        }
    }
    array[low][0] = key;
    array[low][1] = key_;
    quick_sort_(array, i, low-1);
    quick_sort_(array, low+1, j);
}