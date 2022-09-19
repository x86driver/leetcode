class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        lastRow = len(matrix) - 1
        i = 0
        while i < len(matrix[lastRow]):
            curr = matrix[lastRow][i]
            x = lastRow
            y = i
            while x >= 0 and y >= 0:
                if matrix[x][y] != curr:
                    return False
                x -= 1
                y -= 1
            i += 1

        lastCol = len(matrix[lastRow]) - 1
        i = lastRow - 1
        while i > 0:
            curr = matrix[i][lastCol]
            x = i
            y = lastCol
            while x >= 0 and y >= 0:
                if matrix[x][y] != curr:
                    return False
                x -= 1
                y -= 1
            i -= 1

        return True
