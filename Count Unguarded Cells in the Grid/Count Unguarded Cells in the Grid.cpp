// Solution for Count Unguarded Cells in the Grid in CPP

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Create a grid initialized with 0 (empty cell)
        // We'll mark:
        // 0 → empty cell
        // 1 → guarded cell (visible by a guard)
        // 2 → blocked cell (either a guard or wall)
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark all guard positions as blocked (2)
        for (const auto& guard : guards) {
            int row = guard[0], col = guard[1];
            grid[row][col] = 2;
        }
        
        // Mark all wall positions as blocked (2)
        for (const auto& wall : walls) {
            int row = wall[0], col = wall[1];
            grid[row][col] = 2;
        }
        
        // Directions → down, left, up, right
        vector<vector<int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        
        // For each guard, simulate their line of sight in all four directions
        for (const auto& guard : guards) {
            int row = guard[0], col = guard[1];
            
            for (const auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                // Continue moving in the same direction until blocked
                while (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] != 2) {
                    // Mark the cell as guarded
                    grid[newRow][newCol] = 1;
                    newRow += dir[0];
                    newCol += dir[1];
                }
            }
        }
        
        // Count cells that remain unoccupied (0 → neither guarded nor blocked)
        int unguardedCells = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    unguardedCells++;
                }
            }
        }
        
        // Return the total number of unguarded cells
        return unguardedCells;
    }
};
