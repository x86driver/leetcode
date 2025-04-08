class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<pair<int, int>> st; // value -> index
        vector<int> ans;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] >= st.top().first) {
                st.pop();
            }
            st.push({heights[i], i});
        }

        while (!st.empty()) {
            ans.push_back(st.top().second);
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
