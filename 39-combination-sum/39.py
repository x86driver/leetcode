class Solution:
    def find(self, nums, index, target):
        if sum(self.sets) == target:
            self.ans.append(self.sets.copy())
            return
        elif sum(self.sets) > target:
            return
        elif index >= len(nums):
            return

        self.find(nums, index+1, target)

        self.sets.append(nums[index])
        self.find(nums, index, target)
        self.sets.pop()

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.sets = []
        self.ans = []
        self.find(candidates, 0, target)

        return self.ans
