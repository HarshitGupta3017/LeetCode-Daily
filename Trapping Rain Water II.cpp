class Solution {
public:
    using PP = pair<int, pair<int, int>>;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<PP, vector<PP>, greater<>> boundaryCells;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int row = 0; row < m; row++) {
            for (int col: {0, n - 1}) {
                boundaryCells.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        }
        for (int col = 0; col < n; col++) {
            for (int row: {0, m - 1}) {
                boundaryCells.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        }
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int water = 0;
        while (!boundaryCells.empty()) {
            auto [height, idx] = boundaryCells.top();
            boundaryCells.pop();
            int i = idx.first, j = idx.second;
            for (const auto& dir: directions) {
                int i_ = i + dir[0], j_ = j + dir[1];
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !vis[i_][j_]) {
                    water += max(height - heightMap[i_][j_], 0);
                    boundaryCells.push({max(height, heightMap[i_][j_]), {i_, j_}});
                    vis[i_][j_] = true;
                }
            }
        }
        return water;
    }
};
