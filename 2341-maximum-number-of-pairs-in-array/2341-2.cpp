class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> m(101);
        for (int n : nums) {
            ++m[n];
        }
        int pairs = 0;
        int left = 0;
        for (int i = 0; i <= 100; ++i) {
            pairs += m[i] / 2;
            m[i] %= 2;
            left += m[i];
        }
        return {pairs, left};
    }
};
