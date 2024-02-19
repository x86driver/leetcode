/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int len = numsSize * 2;
    int *ans = calloc(len, sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }
    *returnSize = len;
    return ans;
}
