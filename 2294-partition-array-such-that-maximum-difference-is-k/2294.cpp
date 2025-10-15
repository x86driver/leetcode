class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int curr_min = nums[0];
        for (int n : nums) {
            if (n - curr_min > k) {
                curr_min = n;
                ++count;
            }
        }
        return count;
    }
};
