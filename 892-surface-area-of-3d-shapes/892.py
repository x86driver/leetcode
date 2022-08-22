class Solution:
    def calTop(self, grid, i, j):
        item = grid[i][j]
        topIndex = i - 1
        if topIndex < 0:
            return item
        else:
            top = grid[topIndex][j]
            if (item - top) < 0:
                return 0
            else:
                return item - top
    def calBottom(self, grid, i, j):
        item = grid[i][j]
        bottomIndex = i + 1
        if bottomIndex >= len(grid):
            return item
        else:
            bottom = grid[bottomIndex][j]
            if (item - bottom) < 0:
                return 0
            else:
                return item - bottom

    def calLeft(self, grid, i, j):
        item = grid[i][j]
        leftIndex = j - 1
        if leftIndex < 0:
            return item
        else:
            left = grid[i][leftIndex]
            if (item - left) < 0:
                return 0
            else:
                return item - left

    def calRight(self, grid, i, j):
        item = grid[i][j]
        rightIndex = j + 1
        if rightIndex >= len(grid[i]):
            return item
        else:
            right = grid[i][rightIndex]
            if (item - right) < 0:
                return 0
            else:
                return item - right

    def surfaceArea(self, grid: List[List[int]]) -> int:
        surface = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                surface += self.calTop(grid, i, j)
                surface += self.calBottom(grid, i, j)
                surface += self.calLeft(grid, i, j)
                surface += self.calRight(grid, i, j)
                if grid[i][j] > 0:
                    surface += 2

        return surface
