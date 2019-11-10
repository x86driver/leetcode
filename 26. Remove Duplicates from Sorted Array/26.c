#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return numsSize;
    }

    int index = 0;              // 紀錄目前連續的數字在第幾個
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == nums[index]) {
            ++i;                // 已經有連續兩個一樣的數字, 從下一個開始繼續找
            for (; i < numsSize; ++i) {
                if (nums[i] != nums[index]) { // 一直找到下一個不同的數字
                    break;
                }
            }
            if (i < numsSize) {
                ++index;
                nums[index] = nums[i];
            }
        } else {
            ++index;
            nums[index] = nums[i];
        }
    }
    return index + 1;
}

int main() {
    int ret = 0;
    //    int nums[] = {1,1,2};
    //int nums[] = {1,3,3,4};
    //int nums[] = {0,0,1,1};
    //int nums[] = {0,0,1,1,1,2,2,3,3,4};
    //int nums[] = {};
    //int nums[] = {1};
    int nums[] = {1,1,2,3};
    ret = removeDuplicates(nums, sizeof(nums)/sizeof(int));
    printf("%d\n", ret);
    for (int i = 0; i < ret; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
