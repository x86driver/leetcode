class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [math.inf] * len(nums)
        dp[0] = 0
        for i in range(len(nums)):
            for j in range(i+1, i+nums[i]+1):
                if j < len(nums):
                    dp[j] = min(dp[j], dp[i] + 1)
                if j == len(nums) - 1:
                    return dp[j]

        return dp[-1]
