class Solution:
    def search(self, nums, target):
        head = 0
        tail = len(nums) - 1

        while head <= tail:
            mid = head + ((tail - head) // 2)
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                head = mid + 1
            else:
                tail = mid - 1

        return tail

    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        ans = []
        prefix = [0] * len(nums)
        nums = sorted(nums)

        prefix[0] = nums[0]
        for i in range(1, len(nums)):
            prefix[i] = nums[i] + prefix[i-1]

        for q in queries:
            ans.append(self.search(prefix, q)+1)

        return ans
