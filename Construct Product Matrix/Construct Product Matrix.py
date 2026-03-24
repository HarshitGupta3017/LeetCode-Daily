# Solution for Construct Product Matrix in PY

class Solution:
    def constructProductMatrix(self, grid):
        MOD = 12345

        rows = len(grid)
        cols = len(grid[0])

        result = [[0] * cols for _ in range(rows)]

        # STEP 1: Suffix product
        suffix_product = 1

        for r in range(rows - 1, -1, -1):
            for c in range(cols - 1, -1, -1):
                result[r][c] = suffix_product
                suffix_product = (suffix_product * grid[r][c]) % MOD

        # STEP 2: Prefix product
        prefix_product = 1

        for r in range(rows):
            for c in range(cols):
                result[r][c] = (prefix_product * result[r][c]) % MOD
                prefix_product = (prefix_product * grid[r][c]) % MOD

        return result
