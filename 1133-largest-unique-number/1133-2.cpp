class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        vector<int> m(1001);
        for (int n : nums)
            ++m[n];
        for (int i = m.size() - 1; i >= 0; --i) {
            if (m[i] == 1)
                return i;
        }
        return -1;
    }
};
