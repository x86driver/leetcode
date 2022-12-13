class Solution:
    def nthUglyNumber(self, n: int) -> int:
        n2 = 0
        n3 = 0
        n5 = 0
        uglys = [1] * n

        for i in range(1, n):
            minN = min(uglys[n2] * 2, uglys[n3] * 3, uglys[n5] * 5)

            uglys[i] = minN

            if uglys[i] == uglys[n2] * 2:
                n2 += 1
            if uglys[i] == uglys[n3] * 3:
                n3 += 1
            if uglys[i] == uglys[n5] * 5:
                n5 += 1

        return uglys[-1]
