class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            if (nums[start] == val) {
                while (end > start) {
                    if (nums[end] == val) {
                        --end;
                    } else {
                        break;
                    }
                }
                swap(nums[start], nums[end]);
                ++start;
                --end;
            } else {
                ++start;
            }
        }
        int count = 0;
        for (int n : nums) {
            if (n == val) {
                break;
            }
            ++count;
        }
        return count;
    }
};
