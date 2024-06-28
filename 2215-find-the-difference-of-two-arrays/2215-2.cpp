class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> m(2001);
        for (int n : nums1)
            m[1000 - n] = true;
        set<int> ans2;
        for (int n : nums2)
            if (m[1000 - n] == false)
                ans2.insert(n);
        m.clear();
        m.resize(2001);
        for (int n : nums2)
            m[1000 - n] = true;
        set<int> ans1;
        for (int n : nums1)
            if (!m[1000 - n])
                ans1.insert(n);
        vector<vector<int>> result = {vector<int>(ans1.begin(), ans1.end()), vector<int>(ans2.begin(), ans2.end())};
        return result;
    }
};
