# Solution for Last Day Where You Can Still Cross in PY

class Solution:
    # Directions for 4-way movement
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def dfs(self, grid: List[List[int]], r: int, c: int) -> bool:
        # Out of bounds or already water / visited
        if (r < 0 or r >= len(grid) or
            c < 0 or c >= len(grid[0]) or
            grid[r][c] == 1):
            return False

        # Reached bottom row
        if r == len(grid) - 1:
            return True

        # Mark visited
        grid[r][c] = 1

        # Explore all directions
        for dr, dc in self.directions:
            if self.dfs(grid, r + dr, c + dc):
                return True

        return False

    def canCross(self, cells: List[List[int]], mid: int, row: int, col: int) -> bool:
        # Initialize grid as all land
        grid = [[0] * col for _ in range(row)]

        # Flood cells up to given day
        for i in range(mid + 1):
            r, c = cells[i]
            grid[r - 1][c - 1] = 1

        # Try DFS from each land cell in top row
        for c in range(col):
            if grid[0][c] == 0 and self.dfs(grid, 0, c):
                return True

        return False

    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        left, right = 0, len(cells) - 1
        last_valid_day = 0

        while left <= right:
            mid = left + (right - left) // 2

            if self.canCross(cells, mid, row, col):
                last_valid_day = mid + 1  # convert to 1-based day
                left = mid + 1
            else:
                right = mid - 1

        return last_valid_day
