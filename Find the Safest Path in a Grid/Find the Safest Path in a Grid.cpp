// Solution for Find the Safest Path in a Grid in CPP

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // BFS from (0,0) to (n-1,n-1) visiting only cells whose distance from the
    // nearest thief is >= minSafeness. Returns true if the destination is reachable.
    bool canReachWithSafeness(vector<vector<int>>& distFromThief, int minSafeness, int n) {
        // The source cell itself must satisfy the safeness threshold,
        // otherwise no path starting here can achieve minSafeness.
        if (distFromThief[0][0] < minSafeness) return false;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if (row == n - 1 && col == n - 1) return true;

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) continue;
                if (visited[newRow][newCol]) continue;

                // Only enter cells that keep the path's minimum distance >= minSafeness.
                if (distFromThief[newRow][newCol] < minSafeness) continue;

                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Multi-source BFS from every thief cell simultaneously.
        // This computes the minimum Manhattan distance from each cell to its
        // nearest thief in O(n^2) — far cheaper than computing it per cell.
        vector<vector<int>> distFromThief(n, vector<int>(n, -1));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> bfsQueue;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    bfsQueue.push({i, j});
                    visited[i][j] = true;
                    // Thief cells are distance 0 from themselves.
                    distFromThief[i][j] = 0;
                }
            }
        }

        // Level-order BFS: each wave assigns the correct minimum distance
        // to all cells at the same BFS depth from the nearest thief.
        int dist = 0;
        while (!bfsQueue.empty()) {
            int waveFront = bfsQueue.size();
            while (waveFront--) {
                auto [row, col] = bfsQueue.front();
                bfsQueue.pop();

                distFromThief[row][col] = dist;

                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) continue;
                    if (visited[newRow][newCol]) continue;

                    visited[newRow][newCol] = true;
                    bfsQueue.push({newRow, newCol});
                }
            }
            dist++;
        }

        // Binary search on the safeness factor.
        // If a path exists with safeness >= mid, try higher; otherwise try lower.
        // Upper bound is n + n - 2 (max possible Manhattan distance in an n x n grid),
        // but 400 safely covers the constraint n <= 400.
        int lo = 0, hi = 400, bestSafeness = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReachWithSafeness(distFromThief, mid, n)) {
                bestSafeness = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return bestSafeness;
    }
};
