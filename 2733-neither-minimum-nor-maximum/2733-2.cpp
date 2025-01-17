class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;

        for (int n : nums) {
            minimum = min(minimum, n);
            maximum = max(maximum, n);
        }

        for (int n : nums) {
            if (n != maximum && n != minimum) {
                return n;
            }
        }
        return -1;
    }
};
