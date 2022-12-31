#define max(a,b) (((a) > (b)) ? (a) : (b))

int maxProfit(int* prices, int pricesSize){
    int **f = (int**)calloc(pricesSize + 1, sizeof(int*));
    for (int i = 0; i < pricesSize + 1; ++i) {
        f[i] = (int*)calloc(2, sizeof(int));
        f[i][0] = INT_MIN;
        f[i][1] = INT_MIN;
    }

    f[0][0] = 0;

    for (int i = 1; i < pricesSize + 1; ++i) {
        f[i][0] = max(f[i-1][1] + prices[i-1], f[i-1][0]);
        f[i][1] = max(f[i-1][0] - prices[i-1], f[i-1][1]);
    }

    int ans = f[pricesSize][0];

    for (int i = 0; i < pricesSize + 1; ++i) {
        free(f[i]);
    }
    free(f);

    return ans;
}
