class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        table = Counter(nums)
        ans = []
        for i in range(len(nums)):
            if table[i+1] == 0:
                ans.append(i+1)

        return ans
