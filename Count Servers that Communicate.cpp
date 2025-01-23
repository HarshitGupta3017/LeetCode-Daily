class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowC(m, 0), colC(n, 0);
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    rowC[row]++;
                    colC[col]++;
                }
            }
        }
        int res = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1 && (rowC[row] > 1 || colC[col] > 1)) {
                    res++;
                }
            }
        }
        return res;
    }
};
