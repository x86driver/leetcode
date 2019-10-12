#include <stdio.h>
#include <stdbool.h>

int maxProfit(int *prices, int priceSize) {
    int profit = 0;
    for (int i = 0; i < priceSize - 1; ++i) {
        int today = prices[i];
        int tomorrow = prices[i + 1];
        int diff = tomorrow - today;
        if (diff > 0) {
            profit += diff;
        }
    }
    return profit;
}

int main() {
    //int prices[] = {7,1,5,3,6,4};
    //int prices[] = {1,2,3,4,5};
    //int prices[] = {7,6,4,3,1};
    int prices[] = {2,1,2,0,1};
    int ans = maxProfit(prices, sizeof(prices)/sizeof(prices[0]));
    printf("%d\n", ans);
    return 0;
}
