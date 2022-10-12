class Solution:
    def dfs(self, grid, x, y):
        grid[x][y] = "0"

        if (x-1) >= 0 and grid[x-1][y] == "1":
            self.dfs(grid, x-1, y)
        if (x+1) < len(grid) and grid[x+1][y] == "1":
            self.dfs(grid, x+1, y)
        if (y-1) >= 0 and grid[x][y-1] == "1":
            self.dfs(grid, x, y-1)
        if (y+1) < len(grid[0]) and grid[x][y+1] == "1":
            self.dfs(grid, x, y+1)

    def numIslands(self, grid: List[List[str]]) -> int:
        num = 0

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    num += 1
                    self.dfs(grid, i, j)

        return num
