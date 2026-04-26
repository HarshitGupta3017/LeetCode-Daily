// Solution for Detect Cycles in 2D Grid in JAVA

class Solution {

    // Directions: left, down, up, right
    int[][] directions = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}};
    int rows, cols;

    // DFS to detect cycle
    boolean dfs(boolean[][] visited, char[][] grid,
                int currentRow, int currentCol,
                int parentRow, int parentCol) {

        visited[currentRow][currentCol] = true;

        for (int[] dir : directions) {
            int nextRow = currentRow + dir[0];
            int nextCol = currentCol + dir[1];

            // Boundary check
            if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols)
                continue;

            // Only move to same character
            if (grid[nextRow][nextCol] != grid[currentRow][currentCol])
                continue;

            // Skip parent
            if (nextRow == parentRow && nextCol == parentCol)
                continue;

            // Cycle found
            if (visited[nextRow][nextCol])
                return true;

            if (dfs(visited, grid, nextRow, nextCol, currentRow, currentCol))
                return true;
        }

        return false;
    }

    public boolean containsCycle(char[][] grid) {

        rows = grid.length;
        cols = grid[0].length;

        boolean[][] visited = new boolean[rows][cols];

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (!visited[row][col]) {
                    if (dfs(visited, grid, row, col, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
}
