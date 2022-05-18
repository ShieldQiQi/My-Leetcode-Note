#include <stdio.h>
#include <stdlib.h>

// 

int trap(int* height, int heightSize)
{
    int total_volume = 0;
    int left = 0, right = heightSize - 1;
    int left_max = 0, right_max = 0;
    
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : (total_volume += (left_max - height[left]));
            ++left;
        } else {
            height[right] >= right_max ? (right_max = height[right]) : (total_volume += (right_max - height[right]));
            --right;
        }
    }

    return total_volume;
}

int main()
{
    int height[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d", trap(height, 12));

    return 0;
}


// 快排双指针法

// void quick_sort2(int (*array)[2], int low, int high, int index);

// int trap(int* height, int heightSize)
// {
//     int total_volume = 0;
//     int tmp[20000][2];
//     int count = 1;
//     int left, right;
//     tmp[0][0] = height[0];
//     tmp[0][1] = 0;
//     for (int i = 1; i < heightSize; i++) {
//         if (height[i] != height[i-1]) {
//             tmp[count][0] = height[i];
//             tmp[count][1] = i;
//             count++;
//         }
//     }

//     quick_sort2(tmp, 0, count - 1, 0);
//     left = right = tmp[count - 1][1];
//     count -= 2;
//     while (count > 0) {
//         if (tmp[count][1] < left) {
//             int min = fmin(height[tmp[count][1]], height[left]);
//             for (int i = tmp[count][1]+1; i < left; i++)
//                 total_volume += (min - height[i]);
//             left = tmp[count][1];
//         } else if (tmp[count][1] > right) {
//             int min = fmin(height[tmp[count][1]], height[right]);
//             for (int i = right + 1; i < tmp[count][1]; i++)
//                 if (min - height[i] > 0)
//                     total_volume += (min - height[i]);
//             right = tmp[count][1];
//         }
//         count--;
//     }
//     return total_volume;
// }

// void quick_sort2(int (*array)[2], int low, int high, int index)
// {
//     if(low >= high) // sort ended
//         return;
//     int i= low;
//     int j= high;
//     int key = array[low][index];
//     int key2 = array[low][!index];

//     while(low < high)
//     {
//         while(array[high][index]>=key && low<high)
//         {
//             high--;
//         }
//         if(key > array[high][index])
//         {
//             array[low][index] = array[high][index];
//             array[low][!index] = array[high][!index];
//             low++;
//         }
//         while(array[low][index]<=key && low<high)
//         {
//             low++;
//         }
//         if(key < array[low][index])
//         {
//             array[high][index] = array[low][index];
//             array[high][!index] = array[low][!index];
//             high--;
//         }
//     }
//     array[low][index] = key;
//     array[low][!index] = key2;
//     quick_sort2(array, i, low-1, index);
//     quick_sort2(array, low+1, j, index);
// }

