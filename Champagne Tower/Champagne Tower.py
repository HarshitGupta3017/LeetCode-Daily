# Solution for Champagne Tower in PY

class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:

        memo = [[-1.0 for _ in range(101)] for _ in range(101)]

        def computeAmount(row, col):
            # Invalid positions
            if row < 0 or col < 0 or col > row:
                return 0.0

            # Base case
            if row == 0 and col == 0:
                return poured

            # Already computed
            if memo[row][col] != -1.0:
                return memo[row][col]

            leftParent = max(
                0.0,
                (computeAmount(row - 1, col - 1) - 1.0) / 2.0
            )

            rightParent = max(
                0.0,
                (computeAmount(row - 1, col) - 1.0) / 2.0
            )

            memo[row][col] = leftParent + rightParent
            return memo[row][col]

        return min(1.0, computeAmount(query_row, query_glass))
