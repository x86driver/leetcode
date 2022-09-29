class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        minPrice = math.inf
        currProfit = -math.inf

        for price in prices:
            if price < minPrice and currProfit == -math.inf:
                minPrice = price
            elif (price - minPrice) > currProfit:
                currProfit = price - minPrice
            else:
                profit += currProfit
                currProfit = -math.inf
                minPrice = price

        if currProfit != -math.inf:
            profit += currProfit

        return profit
