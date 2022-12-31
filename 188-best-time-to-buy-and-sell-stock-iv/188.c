#define max(a,b) (((a) > (b)) ? (a): (b))

int maxProfit(int k, int* prices, int pricesSize){
    int f[pricesSize+1][2][k+1];
    for (int i = 0; i < pricesSize + 1; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            f[i][0][j] = -1000000000;
            f[i][1][j] = -1000000000;
        }
    }

    f[0][0][0] = 0;

    int ans = 0;
    for (int i = 1; i < pricesSize + 1; ++i) {
        for (int j = 0; j <= k; ++j) {
            // sell
            f[i][0][j] = max(f[i-1][1][j] + prices[i-1], f[i-1][0][j]);
            // buy
            if (j > 0)
                f[i][1][j] = max(f[i-1][0][j-1] - prices[i-1], f[i-1][1][j]);
            ans = max(ans, f[i][0][j]);
        }
    }

    return ans;
}
