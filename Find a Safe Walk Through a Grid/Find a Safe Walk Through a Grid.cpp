// Solution for Find a Safe Walk Through a Grid in CPP

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // visited[i][j] = best (max) health we reached (i,j) with
        // If we arrive with <= this health, skip (already explored better)
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // BFS queue: {row, col, currentHealth}
        queue<tuple<int,int,int>> q;

        // Start: health reduced if (0,0) is unsafe
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;  // dead before moving!

        q.push({0, 0, startHealth});
        visited[0][0] = startHealth;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();

            // Reached destination with health >= 1
            if (r == m-1 && c == n-1) return true;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                // Health after stepping into neighbour
                int nh = h - grid[nr][nc];

                // Dead → skip
                if (nh <= 0) continue;

                // Already visited with better or equal health → skip
                if (visited[nr][nc] >= nh) continue;

                visited[nr][nc] = nh;
                q.push({nr, nc, nh});
            }
        }

        return false;
    }
};
