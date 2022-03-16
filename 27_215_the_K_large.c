#include <stdio.h>
#include <stdlib.h>
#include <time.h>

inline int partition(int* array, int left, int right)
{
    int key = array[right];
    int low = left-1;
    for(int i=left; i<right; i++)
    {
        if(array[i] <= key)
        {
            int swap = array[++low];
            array[low] = array[i];
            array[i] = swap;
        }
    }
    int swap = array[low+1];
    array[low+1] = array[right];
    array[right] = swap;
    return low+1;
}

inline int randomPartition(int* array, int left, int right)
{
    int index = rand()%(right-left+1)+left;
    int swap = array[index];
    array[index] = array[right];
    array[right] = swap;
    return partition(array, left, right);
}

int quickSelect(int* array, int left, int right, int targetIndex)
{
    int index = randomPartition(array, left, right);
    if (index == targetIndex) {
        return array[index];
    } else {
        return index < targetIndex ? quickSelect(array, index + 1, right, targetIndex)
                         : quickSelect(array, left, index - 1, targetIndex);
    }
}

int findKthLargest(int* nums, int numsSize, int k)
{
    srand(time(0));
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}

int main()
{
    const int numsSize = 6;
    int nums[numsSize] = {3,2,1,5,6,4};

    int kLargest = findKthLargest(nums, numsSize, 2);

    printf("%d", kLargest);

    return 0;
}