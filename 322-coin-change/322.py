class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [math.inf] * (amount + 1)
        dp[0] = 0

        for i in range(1, amount + 1):
            minimal = math.inf
            for c in coins:
                if (i - c) >= 0:
                    minimal = min(minimal, dp[i-c])
            dp[i] = minimal + 1

        if dp[amount] == math.inf:
            return -1
        else:
            return dp[amount]
