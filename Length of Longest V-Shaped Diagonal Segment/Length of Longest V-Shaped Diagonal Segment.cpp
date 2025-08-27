// Solution for Length of Longest V-Shaped Diagonal Segment in CPP

class Solution {
public:

    // Directions for diagonal movement:
    // 0: down-right, 1: down-left, 2: up-left, 3: up-right
    vector<vector<int>> directions = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
    int t[501][501][4][2];

    // Recursive DFS to extend the V-shaped diagonal
    int dfs(int row, int col, int dir, bool canTurn, int expectedVal, 
            vector<vector<int>>& grid, int rows, int cols) {

        // Move one step in the current diagonal direction
        int newRow = row + directions[dir][0];
        int newCol = col + directions[dir][1];

        // Out of bounds OR value doesn't match expected sequence → stop
        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols 
            || grid[newRow][newCol] != expectedVal) {
            return 0;
        }

        if (t[newRow][newCol][dir][canTurn] != -1) {
            return t[newRow][newCol][dir][canTurn];
        }

        int longestPath = 0;

        // Continue moving in the same direction, update expected value (2→0 or 0→2)
        int continueStraight = 1 + dfs(newRow, newCol, dir, canTurn, 
                                       expectedVal == 2 ? 0 : 2, 
                                       grid, rows, cols);

        longestPath = max(longestPath, continueStraight);

        // Optionally make ONE clockwise 90° turn (if allowed)
        if (canTurn) {
            int afterTurn = 1 + dfs(newRow, newCol, (dir + 1) % 4, false, 
                                    expectedVal == 2 ? 0 : 2, 
                                    grid, rows, cols);
            longestPath = max(longestPath, afterTurn);
        }

        return t[newRow][newCol][dir][canTurn] = longestPath;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        memset(t, -1, sizeof(t));

        int maxLength = 0;

        // Try to start from every cell that has a '1'
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    // From each '1', try all 4 diagonal directions
                    for (int dir = 0; dir < 4; dir++) {
                        // Start length = 1 (the '1' itself)
                        maxLength = max(maxLength, 
                                        1 + dfs(r, c, dir, true, 2, grid, rows, cols));
                    }
                }
            }
        }
        return maxLength;
    }
};
