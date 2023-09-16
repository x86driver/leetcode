class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int minimum = nums[0];
        int maximum = nums[0];
        for (int n : nums) {
            minimum = min(minimum, n);
            maximum = max(maximum, n);
        }
        for (int n : nums) {
            if (n != minimum && n != maximum)
                return n;
        }
        return -1;
    }
};
