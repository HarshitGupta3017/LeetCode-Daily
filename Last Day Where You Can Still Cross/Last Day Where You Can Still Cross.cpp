// Solution for Last Day Where You Can Still Cross in CPP

class Solution {
public:
    // Directions for 4-way movement: right, left, down, up
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    /**
     * DFS to check if we can reach the bottom row starting from (r, c)
     * Only allowed to walk on land cells (value = 0)
     */
    bool DFS(vector<vector<int>>& grid, int r, int c) {

        // Out of bounds or already water / visited
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size() ||
            grid[r][c] == 1) {
            return false;
        }

        // Reached bottom row → successful crossing
        if (r == grid.size() - 1) {
            return true;
        }

        // Mark current cell as visited (convert land to water)
        grid[r][c] = 1;

        // Explore all 4 directions
        for (const auto& dir : directions) {
            int newRow = r + dir[0];
            int newCol = c + dir[1];

            if (DFS(grid, newRow, newCol)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Checks if crossing from top to bottom is possible
     * after flooding cells from day 0 to day mid
     */
    bool canCross(vector<vector<int>>& cells, int mid, int row, int col) {

        // Initialize grid as all land
        vector<vector<int>> grid(row, vector<int>(col, 0));

        // Flood cells up to the given day (0-based indexing)
        for (int i = 0; i <= mid; i++) {
            int r = cells[i][0] - 1;  // convert to 0-based index
            int c = cells[i][1] - 1;
            grid[r][c] = 1;          // mark as water
        }

        // Try starting DFS from every land cell in top row
        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0 && DFS(grid, 0, c)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Binary search on the last possible day we can cross
     */
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int left = 0;
        int right = cells.size() - 1;
        int lastValidDay = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If crossing is possible on this day
            if (canCross(cells, mid, row, col)) {
                lastValidDay = mid + 1;  // convert to 1-based day count
                left = mid + 1;          // try later days
            } else {
                right = mid - 1;         // try earlier days
            }
        }

        return lastValidDay;
    }
};
