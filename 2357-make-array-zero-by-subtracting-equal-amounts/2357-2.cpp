class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                int val = nums[i];
                for (int j = i; j < nums.size(); ++j) {
                    nums[j] -= val;
                }
                ++count;
            }
        }

        return count;
    }
};
