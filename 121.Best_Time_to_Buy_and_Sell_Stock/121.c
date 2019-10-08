#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize) {
    if (pricesSize == 0) {
        return 0;
    }
    int min = prices[0];
    int profit = 0;
    for (size_t i = 0; i < pricesSize; ++i) {
        int price = prices[i];
        if (price < min) {
            min = price;
        }
        int dp = price - min;
        if (profit < dp) {
            profit = dp;
        }
    }
    return profit;
}

int main() {
    //    vector<int> prices = {7,1,5,3,6,4};
    //vector<int> prices = {1,2,0,1,3};
    int prices[] = {1,5};
    int ans = maxProfit(prices, sizeof(prices)/sizeof(prices[0]));
    printf("%d\n", ans);
    return 0;
}
