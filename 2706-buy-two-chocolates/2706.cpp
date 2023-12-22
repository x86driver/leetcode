class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minCost = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i + 1; j < prices.size(); ++j) {
                int cost = prices[i] + prices[j];
                minCost = min(minCost, cost);
            }
        }
        if (minCost <= money)
            return money - minCost;
        else
            return money;
    }
};
