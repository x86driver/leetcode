class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count = 0;
        int leftSum = nums[0];
        int rightSum = accumulate(nums.begin() + 1, nums.end(), 0);
        if ((rightSum - leftSum) % 2 == 0) {
            ++count;
        }
        for (int i = 1; i < nums.size() - 1; ++i) {
            leftSum += nums[i];
            rightSum -= nums[i];
            if ((rightSum - leftSum) % 2 == 0) {
               ++count;
            }
        }

        return count;
    }
};
