class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int money = 0;
        for (int i = 0; i < cost.size(); i += 3) {
            money += cost[i];
            if ((i + 1) < cost.size()) {
                money += cost[i + 1];
            }
        }
        return money;
    }
};
