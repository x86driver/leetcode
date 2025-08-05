class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increase = 1;
        int decrease = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int inc = 1;
            int dec = 1;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[j - 1]) {
                    ++inc;
                } else {
                    break;
                }
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] < nums[j - 1]) {
                    ++dec;
                } else {
                    break;
                }
            }
            increase = max(increase, inc);
            decrease = max(decrease, dec);
        }
        return max(increase, decrease);
    }
};
