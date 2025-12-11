# Solution for Count Covered Buildings in PY

class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:

        # Maps row (y) → (minX, maxX)
        rowToMinMaxX = {}

        # Maps column (x) → (minY, maxY)
        colToMinMaxY = {}

        # Step 1: Precompute boundaries
        for x, y in buildings:
            if y not in rowToMinMaxX:
                rowToMinMaxX[y] = [float('inf'), float('-inf')]
            if x not in colToMinMaxY:
                colToMinMaxY[x] = [float('inf'), float('-inf')]

            # Update row boundaries
            rowToMinMaxX[y][0] = min(rowToMinMaxX[y][0], x)
            rowToMinMaxX[y][1] = max(rowToMinMaxX[y][1], x)

            # Update column boundaries
            colToMinMaxY[x][0] = min(colToMinMaxY[x][0], y)
            colToMinMaxY[x][1] = max(colToMinMaxY[x][1], y)

        # Step 2: Count covered buildings
        covered = 0
        for x, y in buildings:
            minX, maxX = rowToMinMaxX[y]
            minY, maxY = colToMinMaxY[x]

            hasLeft = minX < x
            hasRight = x < maxX
            hasBelow = minY < y
            hasAbove = y < maxY

            if hasLeft and hasRight and hasBelow and hasAbove:
                covered += 1

        return covered
