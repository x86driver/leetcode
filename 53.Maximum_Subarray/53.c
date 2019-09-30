#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>

int maxSubArray(int* nums, int numsSize) {
    int max = 0;
    int *dp = (int*)calloc(numsSize, sizeof(int));
    max = dp[0] = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        dp[i] = dp[i-1] + nums[i];
        dp[i] = MAX(dp[i], nums[i]);
        max = MAX(max, dp[i]);
    }
    free(dp);
    return max;
}

int main() {
    //    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int nums[] = {1};
    printf("max: %d\n", maxSubArray(nums, sizeof(nums)/sizeof(*nums)));
    return 0;
}
