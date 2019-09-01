#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int major = nums[0];

    for (int i = 0; i < numsSize; ++i) {
        if (count == 0) {
            major = nums[i];
        }
        if (major == nums[i]) {
            ++count;
        } else {
            --count;
        }
    }

    return major;
}

int main() {
    int n[] = {6,5,5};
    int ret = majorityElement(n, sizeof(n)/sizeof(n[0]));
    printf("%d\n", ret);
    return 0;
}
