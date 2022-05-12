#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_kth_element(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
    int index1 = 0, index2 = 0;

    while (1) {
        if (index1 == nums1Size)
            return nums2[index2 + k - 1];
        if (index2 == nums2Size)
            return nums1[index1 + k - 1];
        if (k == 1)
            return fmin(nums1[index1], nums2[index2]);
        
        int new_index1 = fmin(index1 + k/2 -1, nums1Size-1);
        int new_index2 = fmin(index2 + k/2 -1, nums2Size-1);
        int pivot1 = nums1[new_index1];
        int pivot2 = nums2[new_index2];
        if (pivot1 <= pivot2) {
            k -= new_index1 - index1 + 1;
            index1 = new_index1 + 1;
        } else {
            k -= new_index2 - index2 + 1;
            index2 = new_index2 + 1;
        }
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int total_length = nums1Size + nums2Size;
    if (total_length % 2 == 1)
        return get_kth_element(nums1, nums1Size, nums2, nums2Size, (total_length+1)/2);
    else
        return (get_kth_element(nums1, nums1Size, nums2, nums2Size, total_length/2) + 
                get_kth_element(nums1, nums1Size, nums2, nums2Size, total_length/2+1))/2.0;
}

int main()
{
    int nums1[2] = {1, 2};
    int nums2[3] = {1, 3, 4};
    printf("%f", findMedianSortedArrays(nums1, 2, nums2, 3));
    return 0;
}