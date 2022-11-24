class Solution:
    def isSelfDividing(self, n):
        orig = n
        while n > 0:
            if n % 10 == 0:
                return False
            if (orig % (n % 10)) != 0:
                return False
            n //= 10
        return True

    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = []
        for i in range(left, right+1):
            if self.isSelfDividing(i):
                ans.append(i)
        return ans
