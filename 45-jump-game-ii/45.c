static inline int min(int a, int b) {
    return a < b ? a : b;
}

int jump(int* nums, int numsSize){
    int f[numsSize];
    for (int i = 0; i < numsSize; ++i)
        f[i] = 10000;
    f[0] = 0;

    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < nums[i]; ++j) {
            if (i + j + 1 >= numsSize)
                break;
            f[i + j + 1] = min(f[i + j + 1], f[i] + 1);
        }
    }

    return f[numsSize-1];
}
