class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        maximum = -math.inf
        for customer in accounts:
            maximum = max(maximum, sum(customer))

        return maximum
