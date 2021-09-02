from typing import List
import math

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        size = len(nums)
        times = math.floor(size / 3)
        tables = {}
        ret = []
        for n in nums:
            if n in tables:
                tables[n] = tables[n] + 1
            else:
                tables[n] = 1

        for k, v in tables.items():
            if v > times:
                ret.append(k)

        return ret


if __name__ == '__main__':
    s = Solution()
    ret = s.majorityElement([1, 3, 3])
    for x in ret:
        print(x)
