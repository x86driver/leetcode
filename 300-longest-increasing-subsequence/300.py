class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        ans = 1
        f = [0] * len(nums)

        f[0] = 1
        for i in range(1, len(nums)):
            lis = 1
            for j in range(i):
                if nums[j] < nums[i]:
                    lis = max(lis, f[j] + 1)
            f[i] = lis
            ans = max(ans, f[i])

        return ans
