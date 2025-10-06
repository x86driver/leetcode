class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(24);
        for (int n : candidates) {
            for (int i = 23; i >= 0; --i) {
                bits[i] += static_cast<int>(n & 1);
                n >>= 1;
            }
        }
        int ans = 0;
        for (int b : bits) {
            ans = max(ans, b);
        }
        return ans;
    }
};
