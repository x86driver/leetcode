#define min(a,b) ((a) < (b) ? (a) : (b))

int coinChange(int* coins, int coinsSize, int amount){
    int f[amount + 1];

    for (int i = 0; i < amount + 1; ++i)
        f[i] = INT_MAX;

    f[0] = 0;

    for (int i = 1; i < amount + 1; ++i) {
        for (int j = 0; j < coinsSize; ++j) {
            if (coins[j] <= i)
                f[i] = min(f[i], f[i - coins[j]] + 1);
        }
    }

    if (f[amount] == INT_MAX)
        return -1;
    else
        return f[amount];
}
