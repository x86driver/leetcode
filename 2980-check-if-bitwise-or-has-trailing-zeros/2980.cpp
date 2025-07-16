class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int pair = nums[i] | nums[j];
                pair &= 0x1;
                if (pair == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
