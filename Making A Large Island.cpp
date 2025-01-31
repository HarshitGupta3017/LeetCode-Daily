class Solution {
public:

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int DFS(vector<vector<int>>& grid, int i, int j, int id, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = id;
        int size = 1;
        for (const auto& dir: directions) {
            int i_ = i + dir[0], j_ = j + dir[1];
            size += DFS(grid, i_, j_, id, n);
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int id = 2;
        unordered_map<int, int> mp;
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = DFS(grid, i, j, id, n);
                    result = max(result, size);
                    mp[id++] = size;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIds;
                    for (const auto& dir: directions) {
                        int i_ = i + dir[0], j_ = j + dir[1];
                        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_] != 0) {
                            uniqueIds.insert(grid[i_][j_]);
                        }
                    }
                    int totalSize = 1;
                    for (const auto& id: uniqueIds) {
                        totalSize += mp[id];
                    }
                    result = max(result, totalSize);
                }
            }
        }
        return result;
    }
};
