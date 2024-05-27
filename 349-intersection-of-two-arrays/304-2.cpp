class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> m1(1001);
        vector<bool> m2(1001);
        for (int n : nums1)
            m1[n] = true;
        for (int n : nums2)
            m2[n] = true;
        vector<int> ans;
        for (int i = 0; i < m1.size(); ++i) {
            if (m1[i] && m2[i])
                ans.push_back(i);
        }
        return ans;
    }
};
