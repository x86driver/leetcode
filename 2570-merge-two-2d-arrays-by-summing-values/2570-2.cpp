class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> m(1001);
        for (int i = 0; i < nums1.size(); ++i) {
            m[nums1[i][0]] = nums1[i][1];
        }
        for (int i = 0; i < nums2.size(); ++i) {
            m[nums2[i][0]] += nums2[i][1];
        }
        vector<vector<int>> ans;
        for (int i = 1; i < m.size(); ++i) {
            if (m[i])
                ans.push_back({i, m[i]});
        }
        return ans;
    }
};
