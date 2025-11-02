# Solution for Count Unguarded Cells in the Grid in PY

class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0] * n for _ in range(m)]
        # 0 → empty, 1 → guarded, 2 → blocked

        # Mark guards and walls
        for r, c in guards:
            grid[r][c] = 2
        for r, c in walls:
            grid[r][c] = 2

        dirs = [(1,0), (0,-1), (-1,0), (0,1)]

        # Simulate guard vision
        for r, c in guards:
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                while 0 <= nr < m and 0 <= nc < n and grid[nr][nc] != 2:
                    grid[nr][nc] = 1
                    nr += dr
                    nc += dc

        # Count unguarded cells
        return sum(grid[i][j] == 0 for i in range(m) for j in range(n))
