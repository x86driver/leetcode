class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heapify(nums)
        n = nums[0]
        for i in range(len(nums)-k+1):
            n = heappop(nums)

        return n
