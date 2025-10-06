// Solution for Swim in Rising Water in CPP

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Min-heap to always process the next lowest elevation cell first.
        // Each entry: {cell_elevation, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // Visited matrix to avoid re-processing cells.
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // 4 possible movement directions: right, down, left, up.
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Start at the top-left cell (0, 0)
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int minTime = 0; // Keeps track of the max elevation encountered on the path.

        // Modified Dijkstra's algorithm:
        // At each step, choose the next cell with the smallest elevation.
        while (!minHeap.empty()) {
            auto currentCell = minHeap.top();
            minHeap.pop();

            int currElevation = currentCell[0];
            int row = currentCell[1];
            int col = currentCell[2];

            // Update the minimum time required to reach this cell.
            minTime = max(minTime, currElevation);

            // If we've reached the bottom-right cell, return the time.
            if (row == n - 1 && col == n - 1) {
                return minTime;
            }

            // Explore all 4 neighboring cells.
            for (const auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                // Check valid bounds and avoid revisiting cells.
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    minHeap.push({grid[newRow][newCol], newRow, newCol});
                }
            }
        }

        // If somehow the target is unreachable (shouldn't happen), return -1.
        return -1;
    }
};
