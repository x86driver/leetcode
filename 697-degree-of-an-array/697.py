class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        table = Counter(nums)

        length = math.inf
        max_degree = table.most_common()[0][1]
        if max_degree == 1:
            return 1
        for n,degree in table.most_common():
            if degree == max_degree:
                start = 0
                end = 0
                for i in range(len(nums)):
                    if nums[i] == n:
                        start = i
                        break
                for i in range(len(nums)-1, -1, -1):
                    if nums[i] == n:
                        end = i
                        break
                length = min(length, end-start+1)
            else:
                break

        return length
