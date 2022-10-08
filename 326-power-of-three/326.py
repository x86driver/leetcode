class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        while n > 1:
            if (n % 3) == 0:
                n //= 3
            else:
                return False

        return n == 1
