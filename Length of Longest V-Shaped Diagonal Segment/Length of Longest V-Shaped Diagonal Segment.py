# Solution for Length of Longest V-Shaped Diagonal Segment in PY

class Solution:
    def __init__(self):
        self.directions = [(1,1),(1,-1),(-1,-1),(-1,1)]
        self.t = None

    def dfs(self, row, col, dir, canTurn, expectedVal, grid, rows, cols):
        newRow, newCol = row + self.directions[dir][0], col + self.directions[dir][1]
        if newRow < 0 or newRow >= rows or newCol < 0 or newCol >= cols or grid[newRow][newCol] != expectedVal:
            return 0
        if self.t[newRow][newCol][dir][canTurn] != -1:
            return self.t[newRow][newCol][dir][canTurn]
        continueStraight = 1 + self.dfs(newRow, newCol, dir, canTurn, 0 if expectedVal == 2 else 2, grid, rows, cols)
        longestPath = continueStraight
        if canTurn:
            afterTurn = 1 + self.dfs(newRow, newCol, (dir+1)%4, 0, 0 if expectedVal == 2 else 2, grid, rows, cols)
            longestPath = max(longestPath, afterTurn)
        self.t[newRow][newCol][dir][canTurn] = longestPath
        return longestPath

    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        self.t = [[[[-1]*2 for _ in range(4)] for _ in range(cols)] for _ in range(rows)]
        maxLength = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    for dir in range(4):
                        maxLength = max(maxLength, 1 + self.dfs(r, c, dir, 1, 2, grid, rows, cols))
        return maxLength
