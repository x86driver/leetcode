class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int coins = 0;
        sort(piles.begin(), piles.end());
        int count = piles.size() - (piles.size() / 3 * 2);
        for (int i = piles.size() - 1; i >= count; i -= 2) {
            coins += piles[i - 1];
        }
        return coins;
    }
};
