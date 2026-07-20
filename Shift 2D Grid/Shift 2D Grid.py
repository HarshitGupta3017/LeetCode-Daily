# Solution for Shift 2D Grid in PY

class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        rows, cols = len(grid), len(grid[0])
        total_cells = rows * cols

        k %= total_cells
        if k == 0:
            return grid

        def reverse_segment(lo: int, hi: int) -> None:
            while lo < hi:
                r1, c1 = divmod(lo, cols)
                r2, c2 = divmod(hi, cols)

                grid[r1][c1], grid[r2][c2] = grid[r2][c2], grid[r1][c1]

                lo += 1
                hi -= 1

        reverse_segment(0, total_cells - 1)
        reverse_segment(0, k - 1)
        reverse_segment(k, total_cells - 1)

        return grid
