class Solution:
    def convertToBase7(self, num: int) -> str:
        arr = []
        neg = False
        if num == 0:
            return "0"
        if num < 0:
            neg = True
            num *= -1
        while num != 0:
            arr.append(num % 7)
            num //= 7

        if neg:
            arr.append('-')
        arr.reverse()

        return ''.join(str(x) for x in arr)
