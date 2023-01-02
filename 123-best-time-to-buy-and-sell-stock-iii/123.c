#define max(a,b) ((a) > (b) ? (a): (b))

int maxProfit(int* prices, int pricesSize){
    int f[pricesSize + 1][2][3];

    for (int i = 0; i < pricesSize + 1; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 3; ++k)
                f[i][j][k] = INT_MIN;

    f[0][0][0] = 0;
    int ans = 0;

    for (int i = 0; i < pricesSize; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k <= 2; ++k) {
                if (f[i][j][k] == INT_MIN)
                    continue;
                if (j == 0 && k < 2) {
                    // buy
                    f[i + 1][1][k + 1] = max(f[i + 1][1][k + 1], f[i][j][k] - prices[i]);
                } else if (j == 1) {
                    // sell
                    f[i + 1][0][k] = max(f[i + 1][0][k], f[i][j][k] + prices[i]);
                }
                // rest
                f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k]);
                ans = max(ans, f[i + 1][0][k]);
            }
        }
    }

    return ans;
}
