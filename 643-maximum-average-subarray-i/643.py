class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        prefix = [0]
        for i,v in enumerate(nums):
            prefix.append(prefix[i] + v)
        
        Max = (prefix[k] - prefix[0]) / k
        
        i = 1
        j = i+k
        
        while j < len(prefix):
            s = (prefix[j] - prefix[i]) / k
            Max = max(Max, (prefix[j] - prefix[i]) / k)
            i += 1
            j += 1

        return Max
        
    def findMaxAverage2(self, nums: List[int], k: int) -> float:
        Sum = sum(nums[0:k])
        Max =  Sum / k

        i = 0
        j = k

        while j < len(nums):
            Sum -= nums[i]
            Sum += nums[j]
            Max = max(Max, Sum / k)
            i += 1
            j += 1

        return Max
