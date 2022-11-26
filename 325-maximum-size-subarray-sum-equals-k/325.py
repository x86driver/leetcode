class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        prefix = [nums[0]]
        prefix_map = {nums[0]: 0}
        for i in range(1, len(nums)):
            prefix.append(prefix[i-1] + nums[i])
            if prefix[i] not in prefix_map:
                prefix_map[prefix[i]] = i

        maxLen = 0
        for i in range(len(prefix)):
            if prefix[i] == k:
                maxLen = i + 1
            elif (prefix[i] - k) in prefix_map:
                maxLen = max(maxLen, i - prefix_map[prefix[i]-k])

        return maxLen
