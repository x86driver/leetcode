class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        comm_a = {1, a}
        for i in range(2, (a // 2) + 1):
            if (a % i) == 0:
                comm_a.add(i)

        count = 0
        for i in range(1, (b // 2) + 1):
            if (b % i) == 0 and i in comm_a:
                count += 1

        if b in comm_a:
            count += 1

        return count
