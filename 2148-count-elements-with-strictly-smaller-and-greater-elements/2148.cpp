class Solution {
public:
    int countElements(vector<int>& nums) {
        if (nums.size() <= 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int start = 0, end = 0;
        int minimum = nums[0];
        int maximum = nums.back();
        for (start = 1; start < nums.size(); ++start) {
            if (nums[start] > minimum) {
                break;
            }
        }
        for (end = nums.size() - 2; end >= 0; --end) {
            if (nums[end] < maximum) {
                break;
            }
        }

        int ans = end - start + 1;
        if (ans < 0) {
            return 0;
        } else {
            return ans;
        }
    }
};
