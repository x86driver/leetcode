class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = 0;
        int right = 0;

        for (left = nums.size() - 1; left > 0; --left) {
            if (nums[left-1] < nums[left]) {
                --left;
                break;
            }
        }

        int minRight = 101;
        int minRightIndex = 0;

        for (right = left + 1; right < nums.size(); ++right) {
            if (nums[right] > nums[left]) {
                if (nums[right] <= minRight) {
                    minRight = nums[right];
                    minRightIndex = right;
                }
            }
        }

        if (left == minRightIndex) {
            reverse(nums.begin(), nums.end());
        } else {
            int tmp = nums[left];
            nums[left] = nums[minRightIndex];
            nums[minRightIndex] = tmp;

            reverse(nums.begin() + left + 1, nums.end());
        }
    }
};
