class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> s;
        map<int, int> m;

        for (int n: nums2) {
            while (!s.empty() && n > s.top()) {
                int v = s.top();
                m[v] = n;
                s.pop();
            }
            s.push(n);
        }

        while (!s.empty()) {
            int v = s.top();
            m[v] = -1;
            s.pop();
        }

        for (int n: nums1) {
            if (m.find(n) == m.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(m[n]);
            }
        }

        return ans;
    }
};
