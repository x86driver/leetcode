class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maximum = 0;
        for (int n : nums) {
            if (n == 0) {
                maximum = max(maximum, count);
                count = 0;
            } else {
                ++count;
            }
        }
        return max(maximum, count);
    }
};
