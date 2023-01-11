class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> s;
        s.push_back(nums2[0]);

        for (int i = 1; i < nums2.size(); ++i) {
            while (!s.empty() && s.back() < nums2[i]) {
                m[s.back()] = nums2[i];
                s.pop_back();
            }
            s.push_back(nums2[i]);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            if (m.find(nums1[i]) != m.end())
                ans.push_back(m[nums1[i]]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
