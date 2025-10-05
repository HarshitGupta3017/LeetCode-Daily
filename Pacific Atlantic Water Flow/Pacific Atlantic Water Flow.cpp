// Solution for Pacific Atlantic Water Flow in CPP

class Solution {
public:
    // DFS helper function to mark all cells reachable from a given ocean
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& reachable, int row, int col) {
        int m = heights.size();
        int n = heights[0].size();

        // Mark current cell as reachable
        reachable[row][col] = true;

        // Possible directions: right, down, left, up
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (const auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            // Check bounds, not visited, and height allows water flow
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !reachable[newRow][newCol] &&
                heights[newRow][newCol] >= heights[row][col]) {
                dfs(heights, reachable, newRow, newCol); // Continue DFS
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // Track cells reachable by Pacific and Atlantic oceans
        vector<vector<bool>> pacificReachable(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticReachable(m, vector<bool>(n, false));

        // Run DFS from Pacific borders (top row and left column)
        for (int i = 0; i < m; i++) {
            dfs(heights, pacificReachable, i, 0);
            dfs(heights, atlanticReachable, i, n - 1); // Run DFS from Atlantic borders (right column)
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacificReachable, 0, j); // Pacific top row
            dfs(heights, atlanticReachable, m - 1, j); // Atlantic bottom row
        }

        // Collect cells reachable by both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificReachable[i][j] && atlanticReachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
