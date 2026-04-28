# Solution for Minimum Operations to Make a Uni-Value Grid in PY

class Solution:
    def minOperations(self, grid: list[list[int]], x: int) -> int:

        # Step 1: Flatten the 2D grid into a 1D list
        flattened_values = [value for row in grid for value in row]

        # Step 2: Sort values to easily pick median
        flattened_values.sort()

        total_elements = len(flattened_values)

        # Step 3: Check modular consistency
        required_remainder = flattened_values[0] % x

        # Median minimizes total absolute difference
        target_value = flattened_values[total_elements // 2]

        total_operations = 0

        # Step 4: Calculate total operations
        for value in flattened_values:

            # If remainder differs → impossible to equalize
            if value % x != required_remainder:
                return -1

            # Number of operations needed to convert value → targetValue
            total_operations += abs(value - target_value) // x

        return total_operations
