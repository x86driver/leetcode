class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i < (int)nums.size(); ++i)
            if (nums[i] != nums[i - 1])
                ++ans;
        return ans;
    }
};
