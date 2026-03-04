# Solution for Special Positions in a Binary Matrix in PY

class Solution:
    def numSpecial(self, mat):
        total_rows = len(mat)
        total_columns = len(mat[0])

        row_ones_count = [0] * total_rows
        column_ones_count = [0] * total_columns

        # First pass: count 1s in each row and column
        for row in range(total_rows):
            for col in range(total_columns):
                if mat[row][col] == 1:
                    row_ones_count[row] += 1
                    column_ones_count[col] += 1

        # Second pass: count special positions
        special_positions_count = 0

        for row in range(total_rows):
            for col in range(total_columns):
                if (mat[row][col] == 1 and
                    row_ones_count[row] == 1 and
                    column_ones_count[col] == 1):

                    special_positions_count += 1

        return special_positions_count
