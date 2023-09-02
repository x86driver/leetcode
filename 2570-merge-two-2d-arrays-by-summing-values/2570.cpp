class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> m(1001);
        for (const vector<int>& n : nums1)
            m[n[0]] += n[1];
        for (const vector<int>& n : nums2)
            m[n[0]] += n[1];

        vector<vector<int>> ans;

        for (int i = 0; i < 1001; ++i) {
            if (m[i] != 0) {
                ans.push_back({i, m[i]});
            }
        }
        return ans;
    }
};
