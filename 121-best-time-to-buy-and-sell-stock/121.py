class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [0] * len(prices)
        max_arr = [0] * len(prices)

        max_arr[-1] = prices[-1]
        for i in range(len(prices)-2, -1, -1):
            max_arr[i] = max(prices[i], max_arr[i+1])

        for i in range(len(prices)-1):
            dp[i] = max_arr[i+1] - prices[i]

        return max(dp)
