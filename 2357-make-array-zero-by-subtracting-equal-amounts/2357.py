class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        h = []
        count = 0

        for n in nums:
            if n != 0:
                heappush(h, n)

        while len(h) > 0:
            x = heappop(h)
            h = []
            for i in range(len(nums)):
                if nums[i] > 0:
                    nums[i] -= x
                if nums[i] > 0:
                    heappush(h, nums[i])
            count += 1

        return count
