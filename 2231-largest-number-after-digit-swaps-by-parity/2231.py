class Solution:
    def largestInteger(self, num: int) -> int:
        odd = []
        even = []
        array = [int(i) for i in str(num)]

        for a in array:
            if a % 2 == 0:
                heappush(even, -a)
            else:
                heappush(odd, -a)

        ret = 0
        for a in array:
            if a % 2 == 0:
                ret = ret * 10 - heappop(even)
            else:
                ret = ret * 10 - heappop(odd)

        return ret
