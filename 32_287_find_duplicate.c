#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int* nums, int numsSize)
{
    int fast = 0, slow = 0;
    while(1) {
        fast = nums[nums[fast]];
        slow = nums[slow];
        printf("%d %d\n", slow, fast);
        if(slow == fast) {
            fast = 0;
            while(nums[slow] != nums[fast]) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return nums[slow];
        }
    }
}

int main()
{
    int nums[5] = {1,3,4,2,2};
    int result = findDuplicate(nums, 5);

    printf("%d", result);

    return 0;
}