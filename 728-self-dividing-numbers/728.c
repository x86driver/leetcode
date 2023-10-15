/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isSelf(int target) {
    int n = target;
    while (n) {
        int x = n % 10;
        if (x == 0)
            return false;
        if (target % x != 0)
            return false;
        n /= 10;
    }
    return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize){
    int *ret = (int*)calloc(sizeof(int), right - left);
    int index = 0;
    for (int i = left; i <= right; ++i) {
        if (isSelf(i))
            ret[index++] = i;
    }
    *returnSize = index;
    return ret;
}
