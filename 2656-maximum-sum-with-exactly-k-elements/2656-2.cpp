class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int last = nums.back();
        int highest = last + k - 1;
        int result = (last + highest) * k / 2;
        return result;
    }
};
