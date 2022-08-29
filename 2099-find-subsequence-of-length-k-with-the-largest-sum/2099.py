class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        tmp = []
        ans = []
        h = []
        for i,v in enumerate(nums):
            heappush(h, [-v, i])

        for i in range(k):
            tmp.append(heappop(h))

        tmp.sort(key=lambda x: x[1])

        for t in tmp:
            ans.append(-t[0])

        return ans
