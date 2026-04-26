// Solution for Detect Cycles in 2D Grid in CPP

class Solution {
public:

    // Directions: left, down, up, right
    vector<vector<int>> directions = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}};

    int rows, cols;

    // DFS to detect cycle
    bool dfs(vector<vector<bool>>& visited,
             vector<vector<char>>& grid,
             int currentRow,
             int currentCol,
             int parentRow,
             int parentCol) {

        // Mark current cell as visited
        visited[currentRow][currentCol] = true;

        // Explore all 4 directions
        for (const auto& dir : directions) {

            int nextRow = currentRow + dir[0];
            int nextCol = currentCol + dir[1];

            // Boundary check
            if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols)
                continue;

            // Only move to cells with same character
            if (grid[nextRow][nextCol] != grid[currentRow][currentCol])
                continue;

            // Skip the immediate parent cell (important to avoid false cycle)
            if (nextRow == parentRow && nextCol == parentCol)
                continue;

            // If already visited → cycle detected
            if (visited[nextRow][nextCol])
                return true;

            // Continue DFS
            if (dfs(visited, grid, nextRow, nextCol, currentRow, currentCol))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Start DFS from every unvisited cell
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (!visited[row][col]) {
                    if (dfs(visited, grid, row, col, -1, -1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
