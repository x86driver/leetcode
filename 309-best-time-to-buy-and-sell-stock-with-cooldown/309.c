#define max(a,b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize){
    int f[pricesSize + 1][2][2];
    for (int i = 0; i < pricesSize + 1; ++i) {
        f[i][0][0] = -1000000000;
        f[i][0][1] = -1000000000;
        f[i][1][0] = -1000000000;
        f[i][1][1] = -1000000000;
    }

    f[0][0][0] = 0;
    int ans = 0;

    for (int i = 1; i < pricesSize + 1; ++i) {
        int price = prices[i-1];
        // buy
        f[i][1][0] = max(f[i-1][0][0] - price, f[i-1][1][0]);
        // sell
        f[i][0][1] = max(f[i-1][1][0] + price, f[i-1][0][0]);
        // cooldown
        f[i][0][0] = max(f[i-1][0][0], f[i-1][0][1]);
        ans = max(ans, f[i][0][0]);
        ans = max(ans, f[i][0][1]);
    }

    return ans;
}
