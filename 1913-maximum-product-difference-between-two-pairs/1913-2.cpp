class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t last = nums.size() - 1;
        return (nums[last] * nums[last - 1]) - (nums[0] * nums[1]);
    }
};
