class Solution {
public:
    Solution() {
        memset(&dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
    }
    int tribonacci(int n) {
        if (n <= 2)
            return dp[n];
        if (dp[n-1] == 0) {
            dp[n-1] = tribonacci(n-1);
        }
        if (dp[n-2] == 0) {
            dp[n-2] = tribonacci(n-2);
        }
        if (dp[n-3] == 0) {
            dp[n-3] = tribonacci(n-3);
        }
        return dp[n-1] + dp[n-2] + dp[n-3];
    }
private:
    int dp[37];
};
