class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [[0] * n for _ in range(m)]

        for edge in range(n):
            f[0][edge] = 1
        for edge in range(m):
            f[edge][0] = 1

        for i in range(1, m):
            for j in range(1, n):
                f[i][j] = f[i-1][j] + f[i][j-1]

        return f[-1][-1]
