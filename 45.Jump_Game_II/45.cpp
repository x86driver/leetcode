#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using std::min;

int jump(int *nums, int numsSize) {
    if (numsSize == 1) {
        return 0;
    }

    int *dp = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > 0) {
            int start = i + 1;
            int end = min(start + nums[i], numsSize);
            for (int j = start; j < end; ++j) {
                int step = dp[i] + 1;
                if (dp[j] == 0 || dp[j] > step) {
                    dp[j] = step;
                }
            }
        }
    }

    int ans = dp[numsSize - 1];
    free(dp);
    return ans;
}

int main() {
    int nums[] = {2,3,1,1,4};
    int ans = jump(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", ans);
    return 0;
}
