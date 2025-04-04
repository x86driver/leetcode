class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        stack<pair<int, int>> st;
        st.push({prices[0], 0});
        for (int i = 1; i < prices.size(); ++i) {
            while (!st.empty() && st.top().first >= prices[i]) {
                ans[st.top().second] = st.top().first - prices[i];
                st.pop();
            }
            st.push({prices[i], i});
        }
        while (!st.empty()) {
            ans[st.top().second] = st.top().first;
            st.pop();
        }
        return ans;
    }
};
