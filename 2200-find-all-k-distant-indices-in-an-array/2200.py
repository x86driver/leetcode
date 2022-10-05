class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        keys = []
        for i in range(len(nums)):
            if nums[i] == key:
                keys.append(i)

        for i in range(len(nums)):
            for j in range(len(keys)):
                if abs(i-keys[j]) <= k:
                    ans.append(i)
                    break

        return sorted(ans)
