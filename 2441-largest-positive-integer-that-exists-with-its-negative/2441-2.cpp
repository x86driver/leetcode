class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool> m(2001);
        for (int n : nums) {
            m[1000 + n] = true;
        }
        for (int i = 2000; i >= 1000; --i) {
            if (m[i] && m[2000 - i])
                return i - 1000;
        }
        return -1;
    }
};
