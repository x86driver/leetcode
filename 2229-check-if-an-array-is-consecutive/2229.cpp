class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int x = nums[0];
        const int n = nums.size();
        const int last = x + n - 1;
        if (nums.back() != last) {
            return false;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] != 1) {
                return false;
            }
        }
        return true;
    }
};
