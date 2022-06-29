class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        res = []

        pos = 0 # positive pointer
        neg = 0 # negative pointer
        for i,v in enumerate(nums):
            if v >= 0:
                pos = i
                neg = i - 1
                break
        if i == len(nums) - 1:
            pos = i
            neg = i - 1

        while pos < len(nums) and neg >= 0:
            if nums[pos] < abs(nums[neg]):
                res.append(nums[pos] * nums[pos])
                pos += 1
            else:
                res.append(nums[neg] * nums[neg])
                neg -= 1

        while pos < len(nums):
            res.append(nums[pos] * nums[pos])
            pos += 1

        while neg >= 0:
            res.append(nums[neg] * nums[neg])
            neg -= 1

        return res
