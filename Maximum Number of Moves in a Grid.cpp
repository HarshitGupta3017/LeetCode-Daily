class Solution {
public:
    // forward, and both diagonals
    vector<vector<int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col) {
        // base case checking limit of r and c
        if (r < 0 || r >= row || c < 0 || c >= col || vis[r][c]) return 0;
        vis[r][c] = 1;
        int moves = 0;
        // traversing in all directions
        for (const auto& dir: directions) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            // checking new row and col limits now
            // also in ques its saying move to the cell if its value is greater than the current one
            if (new_r >= 0 && new_r < row && new_c >= 0 && new_c < col && grid[new_r][new_c] > grid[r][c]) {
                // adding 1 because if its the valid cell we will increase 1 move
                moves = max(moves, 1 + dfs(new_r, new_c, grid, vis, row, col));
            }
        }
        return moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        // simple dfs based question
        int row = grid.size(), col = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            // we will check each row and for column we are given directions in question
            res = max(res, dfs(i, 0, grid, vis, row, col));
        }
        return res;
    }
};
