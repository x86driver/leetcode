class Solution:
    def largestOddNumber2(self, num: str) -> str:
        tail = len(num) - 1

        while tail >= 0:
            if int(num[tail]) % 2 == 0:
                tail -= 1
            else:
                break

        return num[0:tail+1]
