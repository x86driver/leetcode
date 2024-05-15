class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> m(10e4 + 1);
        for (int n : nums)
            ++m[abs(n)];
        vector<int> ans(nums.size());
        int index = 0;
        for (int i = 0; i < m.size(); ++i) {
            while (m[i]) {
                ans[index++] = i * i;
                --m[i];
            }
        }
        return ans;
    }
};
