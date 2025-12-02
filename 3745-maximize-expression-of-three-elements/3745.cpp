class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t size = nums.size() - 1;
        return nums[size] + nums[size - 1] - nums[0];
    }
};
