class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> s; // index -> val
        vector<int> discount(prices.size(), 0);
        s.push(pair<int, int>(0, prices[0]));

        for (int i = 1; i < prices.size(); ++i) {
            while (!s.empty() && prices[i] <= s.top().second) {
                discount[s.top().first] = prices[i];
                s.pop();
            }
            s.push(pair<int, int>(i, prices[i]));
        }

        vector<int> ans(prices.size(), 0);
        for (int i = 0; i < prices.size(); ++i)
            ans[i] = prices[i] - discount[i];

        return ans;
    }
};
