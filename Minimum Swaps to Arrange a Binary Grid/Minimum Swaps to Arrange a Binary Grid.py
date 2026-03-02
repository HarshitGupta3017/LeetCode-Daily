# Solution for Minimum Swaps to Arrange a Binary Grid in PY

class Solution:
    def minSwaps(self, grid: list[list[int]]) -> int:

        n = len(grid)

        # Step 1: Count trailing zeros
        trailing_zeros = []

        for row in grid:
            zero_count = 0
            for col in reversed(row):
                if col == 0:
                    zero_count += 1
                else:
                    break
            trailing_zeros.append(zero_count)

        total_swaps = 0

        # Step 2: Greedy row fixing
        for target_row in range(n):

            required_zeros = n - target_row - 1
            candidate_row = target_row

            while (candidate_row < n and
                   trailing_zeros[candidate_row] < required_zeros):
                candidate_row += 1

            if candidate_row == n:
                return -1

            # Bubble up
            while candidate_row > target_row:
                trailing_zeros[candidate_row], \
                trailing_zeros[candidate_row - 1] = \
                trailing_zeros[candidate_row - 1], \
                trailing_zeros[candidate_row]

                candidate_row -= 1
                total_swaps += 1

        return total_swaps
