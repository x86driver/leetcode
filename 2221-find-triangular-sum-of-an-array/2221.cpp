class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int x = 1; x < nums.size(); ++x)
            for (int i = 0; i < nums.size() - x; ++i)
                nums[i] = (nums[i] + nums[i + 1]) % 10;

        return nums[0];
    }
};
