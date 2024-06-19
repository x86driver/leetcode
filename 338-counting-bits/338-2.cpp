class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int val = i;
            while (val > 0) {
                count += val % 2;
                val /= 2;
            }
            ans[i] = count;
        }
        return ans;
    }
};
