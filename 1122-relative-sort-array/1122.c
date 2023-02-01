/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int *ans = calloc(arr1Size, sizeof(int));
    *returnSize = arr1Size;
    int count[1001];
    bzero(&count, sizeof(count));

    for (int i = 0; i < arr1Size; ++i)
        ++count[arr1[i]];

    int n = 0;
    for (int i = 0; i < arr2Size; ++i) {
        while (count[arr2[i]] > 0) {
            ans[n++] = arr2[i];
            --count[arr2[i]];
        }
    }

    for (int i = 0; i < 1001; ++i) {
        while (count[i] > 0) {
            ans[n++] = i;
            --count[i];
        }
    }

    return ans;
}
