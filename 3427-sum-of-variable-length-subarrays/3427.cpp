class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int start = max(0, i - nums[i]);
            sum += accumulate(nums.begin() + start, nums.begin() + i + 1, 0);
        }
        return sum;
    }
};
