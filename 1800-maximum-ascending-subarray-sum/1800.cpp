class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                tmp += nums[i];
                sum = max(sum, tmp);
            } else {
                tmp = nums[i];
            }
        }
        sum = max(sum, tmp);
        return sum;
    }
};
