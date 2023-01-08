#define max(a,b) ((a) > (b) ? (a) : (b))

bool canPartition(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; ++i)
        sum += nums[i];
    if ((sum % 2)  != 0)
        return false;

    int M = sum / 2;
    int f[numsSize + 1][M + 1];
    for (int i = 0; i <= numsSize; ++i)
        for (int j = 0; j <= M; ++j)
            f[i][j] = 0;

    f[0][0] = 0;

    for (int i = 1; i <= numsSize; ++i) {
        for (int j = 0; j <= M; ++j) {
            //printf("f[%d][%d] = f[%d][%d] = %d\n", i, j, i-1, j, f[i-1][j]);
            f[i][j] = f[i - 1][j];
        }
        for (int j = nums[i - 1]; j <= M; ++j) {
            //printf("f[%d][%d] = max(%d, f[%d][%d] + %d) = ", i, j, f[i][j], i-1,j-nums[i-1], nums[i - 1]);
            f[i][j] = max(f[i - 1][j], f[i - 1][j - nums[i - 1]] + nums[i - 1]);
            //printf("%d\n", f[i][j]);
            if (f[i][j] == M)
                return true;
        }
    }

    return false;
}

