class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); ++i) {
            m[nums2[i]] = i;
        }
        vector<int> ans;
        for (int n : nums1) {
            ans.push_back(m[n]);
        }
        return ans;
    }
};
