class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> leftSum, rightSum;
        leftSum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            leftSum.push_back(leftSum[i - 1] + nums[i]);
        }
        rightSum.push_back(nums.back());
        int index = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            index = nums.size() - i - 2;
            rightSum.push_back(rightSum[nums.size() - i - 2] + nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (leftSum[i] == rightSum[nums.size() - i - 1]) {
                return i;
            }
        }
        return -1;
    }
};
