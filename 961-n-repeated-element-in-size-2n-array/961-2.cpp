class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> m(10e4 + 1);
        for (int x : nums)
            ++m[x];
        int n = nums.size() / 2;
        for (int i = 0; i < m.size(); ++i) {
            if (m[i] == n)
                return i;
        }
        return -1;
    }
};
