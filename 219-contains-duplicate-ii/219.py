class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        c = Counter(nums[0:k+1])
        for x in c:
            if c[x] > 1:
                return True
        
        i = 0
        j = i+k
        while j < len(nums):
            c[nums[i]] -= 1
            i += 1
            j += 1
            if j >= len(nums):
                break
            c[nums[j]] += 1
            if c[nums[j]] > 1:
                return True

        return False
