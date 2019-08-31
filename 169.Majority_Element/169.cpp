#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

int majorityElement(int* nums, int numsSize) {
    int *count = (int*)calloc(numsSize, sizeof(int));
    unordered_map<int, int> map(numsSize);

    for (int i = 0; i < numsSize; ++i) {
        map[nums[i]]++;
    }

    int max = 0;
    int maxNum = nums[0];

    for (auto &it : map) {
        if (it.second > max) {
            max = it.second;
            maxNum = it.first;
        }
    }
    free(count);

    return maxNum;
}

int main() {
    int n[] = {2, 2, 1, 1, 1, 2, 2};
    int ret = majorityElement(n, sizeof(n)/sizeof(n[0]));
    printf("%d\n", ret);
    return 0;
}
