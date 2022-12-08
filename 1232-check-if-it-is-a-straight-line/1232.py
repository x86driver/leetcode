class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        slope = 0
        vertical = False
        x1 = coordinates[0][0]
        x2 = coordinates[1][0]
        y1 = coordinates[0][1]
        y2 = coordinates[1][1]

        if (x2 - x1) == 0:
            vertical = True
        else:
            slope = (y2 - y1) / (x2 - x1)

        for i in range(1, len(coordinates) - 1):
            x1 = coordinates[i][0]
            x2 = coordinates[i+1][0]
            y1 = coordinates[i][1]
            y2 = coordinates[i+1][1]

            if (x2 - x1) == 0:
                if not vertical:
                    return False
                continue

            new_slope = (y2 - y1) / (x2 - x1)

            if new_slope != slope:
                return False
            if new_slope == 0 and vertical:
                return False

        return True
