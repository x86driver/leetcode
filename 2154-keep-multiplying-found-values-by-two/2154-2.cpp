class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<bool> m(1001);
        for (int n : nums)
            m[n] = true;
        int val = original;
        while (val <= 1000 && m[val]) {
            val *= 2;
        }
        return val;
    }
};
