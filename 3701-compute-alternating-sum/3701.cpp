class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        bool even = true;
        int sum = 0;
        for (int n : nums) {
            if (even) {
                sum += n;
            } else {
                sum -= n;
            }
            even = !even;
        }
        return sum;
    }
};
