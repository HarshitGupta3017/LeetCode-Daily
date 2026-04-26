# Solution for Detect Cycles in 2D Grid in PY

class Solution:
    def containsCycle(self, grid):
        rows, cols = len(grid), len(grid[0])

        directions = [(0, -1), (1, 0), (-1, 0), (0, 1)]
        visited = [[False] * cols for _ in range(rows)]

        def dfs(r, c, pr, pc):
            visited[r][c] = True

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                # Boundary check
                if nr < 0 or nr >= rows or nc < 0 or nc >= cols:
                    continue

                # Same character only
                if grid[nr][nc] != grid[r][c]:
                    continue

                # Skip parent
                if nr == pr and nc == pc:
                    continue

                # Cycle detected
                if visited[nr][nc]:
                    return True

                if dfs(nr, nc, r, c):
                    return True

            return False

        for r in range(rows):
            for c in range(cols):
                if not visited[r][c]:
                    if dfs(r, c, -1, -1):
                        return True

        return False
