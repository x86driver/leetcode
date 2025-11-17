class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> m(101);
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (int n : nums) {
            minimum = min(minimum, n);
            maximum = max(maximum, n);
            m[n] = true;
        }
        vector<int> ans;
        for (int i = minimum; i < maximum; ++i) {
            if (!m[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
