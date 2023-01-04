#define max(a,b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize){
    if (numsSize == 1)
        return nums[0];

    int f[numsSize + 1][2];
    for (int i = 0; i < numsSize + 1; ++i) {
        f[i][0] = INT_MIN;
        f[i][1] = INT_MIN;
    }

    // 不偷1, 可以偷n
    f[0][0] = 0;
    f[1][0] = 0;
    f[1][1] = INT_MIN;

    for (int i = 1; i < numsSize; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                f[i + 1][1] = max(f[i + 1][0], f[i][j] + nums[i]);
            }
            f[i + 1][0] = max(f[i + 1][0], f[i][j]);
        }
    }

    int ans = 0;

    for (int i = 0; i < numsSize + 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans = max(ans, f[i][j]);
        }
    }

    // 不偷 n, 可以偷 1
    f[1][1] = nums[0];
    f[1][0] = 0;

    for (int i = 1; i < numsSize; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                f[i + 1][1] = max(f[i + 1][0], f[i][j] + nums[i]);
            }
            f[i + 1][0] = max(f[i + 1][0], f[i][j]);
        }
    }

    return max(ans, f[numsSize][0]);
}
