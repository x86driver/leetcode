class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for (int n : nums1)
            ++m[n];

        vector<int> ans;
        for (int n : nums2) {
            if (m.find(n) != m.end()) {
                --m[n];
                if (m[n] == 0)
                    m.erase(n);
                ans.push_back(n);
            }
        }

        return ans;
    }
};
