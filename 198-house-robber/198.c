#define max(a,b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize){
    int f[numsSize + 1][2];

    for (int i = 0; i < numsSize + 1; ++i) {
        f[i][0] = INT_MIN;
        f[i][1] = INT_MIN;
    }

    f[0][0] = 0;
    int ans = 0;

    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (f[i][j] == INT_MIN)
                continue;
            if (j == 0)
                f[i + 1][1] = max(f[i + 1][1], f[i][0] + nums[i]);
            f[i + 1][0] = max(f[i + 1][0], f[i][j]);
            ans = max(ans, f[i + 1][0]);
            ans = max(ans, f[i + 1][1]);
        }
    }

    return ans;
}
