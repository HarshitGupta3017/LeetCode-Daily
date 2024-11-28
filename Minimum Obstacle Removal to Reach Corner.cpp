class Solution {
public:
    using P = pair<int, pair<int, int>>;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumObstacles(vector<vector<int>>& grid) {
        // simple dijkstra based question
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        res[0][0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto [d, pos] = pq.top();
            pq.pop();
            int i = pos.first, j = pos.second;
            for (const auto& dir: directions) {
                int x = i + dir[0], y = j + dir[1];
                // if out of bounds continue to next iteration
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                // if obstacle add 1 to weight to remove it
                int wt = (grid[x][y] == 1) ? 1 : 0;
                if (d + wt < res[x][y]) {
                    res[x][y] = d + wt;
                    pq.push({d + wt, {x, y}});
                }
            }
        }
        return res[m - 1][n - 1];
    }
};
