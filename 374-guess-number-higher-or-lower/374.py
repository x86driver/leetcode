# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        if n == 1:
            return 1

        low = 1
        high = n
        pick = 1

        while pick <= n:
            next_pick = (low + high) // 2
            if next_pick == pick:
                pick += 1
            else:
                pick = next_pick
            x = guess(pick)
            if x == 0:
                return pick
            if x == -1:
                high = pick
            elif x == 1:
                low = pick

        return pick
