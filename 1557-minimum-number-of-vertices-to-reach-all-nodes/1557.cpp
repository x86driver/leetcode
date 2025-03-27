class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> m(n);
        vector<int> ans;
        for (const vector<int>& edge : edges) {
            m[edge[1]] = true;
        }
        for (int i = 0; i < n; ++i) {
            if (!m[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
