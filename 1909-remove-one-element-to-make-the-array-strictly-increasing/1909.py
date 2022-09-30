class Solution:
    def isValid(self, nums):
        for i in range(1, len(nums)):
            if nums[i] <= nums[i-1]:
                return False

        return True

    def canBeIncreasing(self, nums: List[int]) -> bool:
        for i in range(len(nums)):
            if self.isValid(nums[0:i]+nums[i+1:]):
                return True

        return False
