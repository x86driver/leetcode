class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> m(101);
        int ans = 0;
        for (int n : nums)
            ++m[n];
        for (int i = 1; i < m.size(); ++i) {
            if (m[i] == 1)
                ans += i;
        }
        return ans;
    }
};
