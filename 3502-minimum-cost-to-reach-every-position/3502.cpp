class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> prefix;
        prefix.push_back(cost[0]);
        for (int i = 1; i < cost.size(); ++i) {
            prefix.push_back(min(prefix[i - 1], cost[i]));
        }
        return prefix;
    }
};
