class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        maxLen = 0
        counter = 0
        table = {}

        for i in range(len(nums)):
            if nums[i]:
                counter += 1
            else:
                counter -= 1

            if counter == 0:
                maxLen = i + 1

            if counter in table:
                maxLen = max(maxLen, i - table[counter])
            else:
                table[counter] = i

        return maxLen
