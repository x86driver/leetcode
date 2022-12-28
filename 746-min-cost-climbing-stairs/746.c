#define min(a,b) (((a) < (b)) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize){
    int dp[2] = {cost[0], cost[1]};

    for (int i = 2; i < costSize; ++i) {
        int curr = min(dp[0], dp[1]) + cost[i];
        dp[i%2] = curr;
    }

    return min(dp[0], dp[1]);
}
