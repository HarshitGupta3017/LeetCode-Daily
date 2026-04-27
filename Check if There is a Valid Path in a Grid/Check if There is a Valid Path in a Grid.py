# Solution for Check if There is a Valid Path in a Grid in PY

class Solution:
    def __init__(self):
        # Mapping each street type to its possible movement directions
        self.streetDirections = {
            1: [(0, -1), (0, 1)],
            2: [(-1, 0), (1, 0)],
            3: [(0, -1), (1, 0)],
            4: [(0, 1), (1, 0)],
            5: [(0, -1), (-1, 0)],
            6: [(-1, 0), (0, 1)]
        }

    def dfs(self, grid, r, c, visited):
        rows, cols = len(grid), len(grid[0])

        # Reached destination
        if r == rows - 1 and c == cols - 1:
            return True

        visited[r][c] = True

        for dr, dc in self.streetDirections[grid[r][c]]:
            nr, nc = r + dr, c + dc

            if nr < 0 or nr >= rows or nc < 0 or nc >= cols or visited[nr][nc]:
                continue

            # Check reverse connection
            for rr, rc in self.streetDirections[grid[nr][nc]]:
                if nr + rr == r and nc + rc == c:
                    if self.dfs(grid, nr, nc, visited):
                        return True

        return False

    def hasValidPath(self, grid):
        rows, cols = len(grid), len(grid[0])
        visited = [[False] * cols for _ in range(rows)]
        return self.dfs(grid, 0, 0, visited)
