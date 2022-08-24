class Solution:
    def reverseBits(self, n: int) -> int:
        val = 0
        for i in range(32):
            tmp = n & 0x01
            n >>= 1
            val |= (tmp << (31 - i))
        return val
