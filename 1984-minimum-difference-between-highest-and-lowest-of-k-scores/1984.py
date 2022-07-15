class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        ptr1 = 0
        ptr2 = k - 1
        minimum = math.inf

        if len(nums) < 2 or k < 2:
            return 0

        nums.sort()

        while ptr1 < len(nums) - k + 1 and ptr2 < len(nums):
            minimum = min(minimum, nums[ptr2] - nums[ptr1])
            ptr1 += 1
            ptr2 += 1

        return minimum
