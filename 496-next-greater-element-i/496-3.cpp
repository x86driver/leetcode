class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        vector<int> ans;
        for (int i = 0; i < nums2.size(); ++i) {
            um[nums2[i]] = i;
        }
        for (int n : nums1) {
            stack<int> st;
            bool found = false;
            for (int index = um[n]; index < nums2.size(); ++index) {
                while (!st.empty() && nums2[index] > n) {
                    ans.push_back(nums2[index]);
                    st.pop();
                    found = true;
                    break;
                }
                if (found) {
                    break;
                }
                st.push(nums2[index]);
            }
            if (!found) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
