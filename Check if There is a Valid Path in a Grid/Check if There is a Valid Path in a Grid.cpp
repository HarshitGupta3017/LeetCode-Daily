// Solution for Check if There is a Valid Path in a Grid in CPP

class Solution {
public:

    // Mapping each street type to its possible movement directions
    unordered_map<int, vector<vector<int>>> streetDirections = {
        {1, {{0, -1}, {0, 1}}},   // left, right
        {2, {{-1, 0}, {1, 0}}},   // up, down
        {3, {{0, -1}, {1, 0}}},   // left, down
        {4, {{0, 1}, {1, 0}}},    // right, down
        {5, {{0, -1}, {-1, 0}}},  // left, up
        {6, {{-1, 0}, {0, 1}}}    // up, right
    };

    // DFS to check if a valid path exists
    bool dfs(vector<vector<int>>& grid,
             int currentRow,
             int currentCol,
             vector<vector<bool>>& visited,
             int totalRows,
             int totalCols) {

        // Reached destination
        if (currentRow == totalRows - 1 && currentCol == totalCols - 1)
            return true;

        visited[currentRow][currentCol] = true;

        // Explore all valid directions from current cell
        for (const auto& direction : streetDirections[grid[currentRow][currentCol]]) {

            int nextRow = currentRow + direction[0];
            int nextCol = currentCol + direction[1];

            // Boundary + visited check
            if (nextRow < 0 || nextRow >= totalRows ||
                nextCol < 0 || nextCol >= totalCols ||
                visited[nextRow][nextCol])
                continue;

            // Check if next cell has a valid back connection
            for (const auto& reverseDir : streetDirections[grid[nextRow][nextCol]]) {

                // If we can come back to current cell → valid connection
                if (nextRow + reverseDir[0] == currentRow &&
                    nextCol + reverseDir[1] == currentCol) {

                    if (dfs(grid, nextRow, nextCol, visited, totalRows, totalCols))
                        return true;
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {

        int totalRows = grid.size();
        int totalCols = grid[0].size();

        vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));

        // Start DFS from top-left cell
        return dfs(grid, 0, 0, visited, totalRows, totalCols);
    }
};
