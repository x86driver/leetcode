class Solution:
    def find(self, nums, index):
        if index >= len(nums):
            self.ans.append(self.sets.copy())
            return

        self.find(nums, index+1)
        self.sets.append(nums[index])
        self.find(nums, index+1)
        self.sets.pop()

    def subsetXORSum(self, nums: List[int]) -> int:
        self.ans = []
        self.sets = []
        self.find(nums, 0)
        result = 0

        for a in self.ans:
            tmp = 0
            for item in a:
                tmp ^= item
            result += tmp

        return result
