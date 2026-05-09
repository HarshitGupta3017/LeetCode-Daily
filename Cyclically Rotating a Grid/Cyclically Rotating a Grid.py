# Solution for Cyclically Rotating a Grid in PY

class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:

        rows = len(grid)
        cols = len(grid[0])

        # Number of layers
        total_layers = min(rows, cols) // 2

        for layer in range(total_layers):

            top_row = layer
            left_col = layer

            bottom_row = rows - layer - 1
            right_col = cols - layer - 1

            layer_elements = []

            # Top row
            for col in range(left_col, right_col):
                layer_elements.append(grid[top_row][col])

            # Right column
            for row in range(top_row, bottom_row):
                layer_elements.append(grid[row][right_col])

            # Bottom row
            for col in range(right_col, left_col, -1):
                layer_elements.append(grid[bottom_row][col])

            # Left column
            for row in range(bottom_row, top_row, -1):
                layer_elements.append(grid[row][left_col])

            layer_size = len(layer_elements)

            # Effective rotation
            rotation_steps = k % layer_size

            # Counter-clockwise rotation
            layer_elements = (
                layer_elements[rotation_steps:] +
                layer_elements[:rotation_steps]
            )

            index = 0

            # Fill back

            # Top row
            for col in range(left_col, right_col):
                grid[top_row][col] = layer_elements[index]
                index += 1

            # Right column
            for row in range(top_row, bottom_row):
                grid[row][right_col] = layer_elements[index]
                index += 1

            # Bottom row
            for col in range(right_col, left_col, -1):
                grid[bottom_row][col] = layer_elements[index]
                index += 1

            # Left column
            for row in range(bottom_row, top_row, -1):
                grid[row][left_col] = layer_elements[index]
                index += 1

        return grid
