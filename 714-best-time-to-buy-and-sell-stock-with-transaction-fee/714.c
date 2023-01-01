#define max(a,b) ((a) > (b) ? (a): (b))

int maxProfit(int* prices, int pricesSize, int fee){
    int f[pricesSize + 1][2];

    for (int i = 0; i < pricesSize + 1; ++i) {
        f[i][0] = -1000000000;
        f[i][1] = -1000000000;
    }

    f[0][0] = 0;
    int ans = 0;

    for (int i = 1; i < pricesSize + 1; ++i) {
        int price = prices[i-1];
        // buy
        f[i][1] = max(f[i-1][0] - price - fee, f[i-1][1]);
        // sell
        f[i][0] = max(f[i-1][1] + price, f[i-1][0]);
        ans = max(ans, f[i][0]);
    }

    return ans;
}
