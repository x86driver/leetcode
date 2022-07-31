class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        stack<pair<int, int>> s;

        for (auto i = 0; i < prices.size(); ++i) {
            int price = prices[i];
            while (!s.empty() && price <= s.top().second) {
                ans[s.top().first] = s.top().second - price;
                s.pop();
            }
            s.push({i, price});
        }

        while (!s.empty()) {
            ans[s.top().first] = s.top().second;
            s.pop();
        }

        return ans;
    }
};
