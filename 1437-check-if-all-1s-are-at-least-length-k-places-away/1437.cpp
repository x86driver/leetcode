class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int left = 0;
        while (left < nums.size()) {
            if (nums[left] == 1) {
                break;
            }
            ++left;
        }
        int right = left + 1;
        if (right == nums.size()) {
            return true;
        }
        while (right < nums.size()) {
            if (nums[right] == 1) {
                break;
            }
            ++right;
        }
        while (right < nums.size()) {
            if (right - left <= k) {
                return false;
            }
            left = right;
            ++right;
            while (right < nums.size()) {
                if (nums[right] == 1) {
                    break;
                }
                ++right;
            }
        }
        return true;
    }
};
