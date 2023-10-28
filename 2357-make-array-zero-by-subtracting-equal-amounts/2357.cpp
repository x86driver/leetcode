class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for (; count < nums.size(); ++count) {
            int minimum = INT_MAX;
            bool zeros = true;
            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] != 0 && nums[i] < minimum)
                    minimum = nums[i];
            }
            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] != 0) {
                    zeros = false;
                    nums[i] -= minimum;
                }
            }
            if (zeros)
                break;
        }
        return count;
    }
};
