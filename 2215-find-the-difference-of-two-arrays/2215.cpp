class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> a1, a2;

        for (int i = 0; i < nums2.size(); ++i) {
            if (s1.find(nums2[i]) == s1.end())
                a2.insert(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if (s2.find(nums1[i]) == s2.end())
                a1.insert(nums1[i]);
        }

        return {vector<int>(a1.begin(), a1.end()),
                vector<int>(a2.begin(), a2.end())};
    }
};
