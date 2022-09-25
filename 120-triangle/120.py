class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        nums = []
        for row in triangle:
            nums.append([0] * len(row))

        nums[0][0] = triangle[0][0]
        for i in range(1, len(triangle)):
            for j in range(len(triangle[i])):
                if (j-1) < 0:
                    prevA = math.inf
                else:
                    prevA = nums[i-1][j-1]
                if j >= len(triangle[i-1]):
                    prevB = math.inf
                else:
                    prevB = nums[i-1][j]

                nums[i][j] = min(prevA, prevB) + triangle[i][j]

        return min(nums[-1])
