#define max(a,b) ((a) > (b) ? (a) : (b))

bool canJump(int* nums, int numsSize){
    int dp[2] = {0, 0};

    for (int i = 1; i < numsSize; ++i) {
        dp[i&1] = max(dp[i-1&1], nums[i-1]) - 1;
        if (dp[i&1] < 0)
            return false;
    }
    return true;
}
