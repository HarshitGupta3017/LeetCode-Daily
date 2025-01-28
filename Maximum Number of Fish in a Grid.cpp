class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int bfs(int i, int j, vector<vector<int>>& grid, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (const auto& dir: directions) {
                int i_ = i + dir[0], j_ = j + dir[1];
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                    q.push({i_, j_});
                    fishCount += grid[i_][j_];
                    grid[i_][j_] = 0;
                }
            }
        }
        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    res = max(res, bfs(i, j, grid, m, n));
                }
            }
        }
        return res;
    }
};
