# Solution for Maximum Matrix Sum in PY

class Solution:
    def maxMatrixSum(self, matrix) -> int:

        # Total sum of absolute values
        total_absolute_sum = 0

        # Smallest absolute value in the matrix
        minimum_absolute_value = float('inf')

        # Count of negative numbers
        negative_count = 0

        matrix_size = len(matrix)

        # Traverse the matrix
        for row in range(matrix_size):
            for col in range(matrix_size):

                current_value = matrix[row][col]

                # Add absolute value
                total_absolute_sum += abs(current_value)

                # Count negatives
                if current_value < 0:
                    negative_count += 1

                # Track minimum absolute value
                minimum_absolute_value = min(
                    minimum_absolute_value, abs(current_value)
                )

        # Apply logic based on negative count parity
        if negative_count % 2 == 0:
            return total_absolute_sum

        return total_absolute_sum - 2 * minimum_absolute_value
