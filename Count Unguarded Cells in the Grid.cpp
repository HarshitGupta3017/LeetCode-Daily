class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // simple question just need to count unguarded cells
        // we can initiate a grid which can indicate 0 for unguarded, 1 for guarded and -1 for guard or 
        // wall
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (const auto& g: guards) {
            grid[g[0]][g[1]] = -1;
        }
        for (const auto& w: walls) {
            grid[w[0]][w[1]] = -1;
        }
        // now we can mark guarded cells
        // as guard can see all 4 directions so we will move there
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (const auto& g: guards) {
            int x = g[0], y = g[1];
            for (const auto& dir: directions) {
                int nx = x + dir.first, ny = y + dir.second;
                // checking boundaries
                // if it has guard or have wall then check for that
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != -1) {
                    // if yes then its guarded
                    grid[nx][ny] = 1;
                    nx += dir.first;
                    ny += dir.second;
                }
            }
        }
        // now count unguarded ones that remained 0
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) count++;
            }
        }
        return count;
    }
};
