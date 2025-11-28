class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (int n : nums) {
            minimum = min(minimum, n);
            maximum = max(maximum, n);
        }
        if ((minimum + k) > maximum) {
            return 0;
        }
        minimum += k;
        maximum -= min(k, maximum - minimum);
        return maximum - minimum;
    }
};
