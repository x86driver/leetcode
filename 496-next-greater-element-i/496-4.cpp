class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        stack<int> st;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && st.top() < nums2[i]) {
                um[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for (int n : nums1) {
            if (um.find(n) == um.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(um[n]);
            }
        }
        return ans;
    }
};
