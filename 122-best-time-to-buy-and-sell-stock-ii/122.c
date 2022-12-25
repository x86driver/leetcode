int maxProfit(int* prices, int pricesSize){
    int curr_min = 10000;
    int curr_max = 0;
    int profit = 0;

    for (int i = 0; i < pricesSize; ++i) {
        if (prices[i] < curr_min) {
            curr_min = curr_max = prices[i];
        } else if (prices[i] > curr_max) {
            curr_max = prices[i];
            profit += curr_max - curr_min;
            curr_min = curr_max;
        }
    }

    return profit;
}
