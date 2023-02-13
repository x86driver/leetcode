class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for (int n : nums1)
            s.insert(n);

        set<int> intersect;
        for (int n : nums2)
            if (s.find(n) != s.end())
                intersect.insert(n);

        vector<int> ans;
        copy(intersect.begin(), intersect.end(), back_inserter(ans));
        return ans;
    }
};
