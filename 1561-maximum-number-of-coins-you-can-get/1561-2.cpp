class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<>());
        int ans = 0;
        for (int i = 0; i < piles.size() / 3 * 2; i += 2) {
            ans += piles[i + 1];
        }
        return ans;
    }
};
