class Solution:
    def canJump(self, nums: List[int]) -> bool:
        valid = [False] * len(nums)
        valid[0] = True

        for i in range(len(nums)):
            if valid[i] == False:
                continue
            if i == 0:
                start = 1
            else:
                if nums[i] < nums[i-1]:
                    continue
                start = i + nums[i-1]
            for j in range(start, i + nums[i] + 1):
                if j < len(nums):
                    if j == len(nums) - 1:
                        return True
                    valid[j] = True
                else:
                    return True

        return valid[-1]
