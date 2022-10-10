class Solution:
    def toHex(self, num: int) -> str:
        ret = []
        h = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']

        if num == 0:
            return "0"
        if num < 0:
            num = 0x100000000 + num

        while num >= 16:
            r = num % 16
            ret.append(h[r])
            num //= 16

        if num > 0:
            ret.append(h[num])

        ret.reverse()
        return ''.join(ret)
