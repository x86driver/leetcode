/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *ans = (int*)calloc(digitsSize + 1, sizeof(int));

    int carry = 1;
    for (int i = 0; i < digitsSize; ++i) {
        int s = digits[digitsSize - i - 1] + carry;
        if (s >= 10) {
            carry = 1;
            s -= 10;
        } else {
            carry = 0;
        }
        ans[digitsSize - i - 1] = s;
    }

    if (carry) {
        *returnSize = digitsSize + 1;
        ans[0] = 1;
    } else {
        *returnSize = digitsSize;
    }
    return ans;
}
