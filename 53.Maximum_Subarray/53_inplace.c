#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>

int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        int curr_sum = nums[i] + nums[i-1];
        nums[i] = MAX(nums[i], curr_sum);
        max = MAX(max, nums[i]);
    }
    return max;
}

int main() {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    //int nums[] = {1};
    printf("max: %d\n", maxSubArray(nums, sizeof(nums)/sizeof(*nums)));
    return 0;
}
