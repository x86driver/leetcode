class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        f = [[0] * n for _ in range(m)]

        if obstacleGrid[0][0] == 0:
            f[0][0] = 1

        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    f[i][j] = 0
                elif i == 0 and j > 0:
                    f[i][j] = f[i][j-1]
                elif j == 0 and i > 0:
                    f[i][j] = f[i-1][j]
                elif i > 0 and j > 0:
                    f[i][j] = f[i-1][j] + f[i][j-1]

        return f[-1][-1]
