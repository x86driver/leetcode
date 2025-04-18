class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> v(101);
        int freq = 0;
        for (int n : nums) {
            ++v[n];
            freq = max(freq, v[n]);
        }
        int ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == freq) {
                ans += v[i];
            }
        }
        return ans;
    }
};
