// Solution for Maximum Number of Points From Grid Queries in CPP

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int q = queries.size();
        vector<int> res(q, 0);
        vector<pair<int, int>> sortedQ;
        for (int i = 0; i < q; i++) {
            sortedQ.push_back({queries[i], i});
        }
        sort(begin(sortedQ), end(sortedQ));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minH;
        vector<vector<int>> vis(m, vector<int>(n, false));
        int points = 0;
        minH.push({grid[0][0], 0, 0});
        vis[0][0] = true;
        for (int i = 0; i < q; i++) {
            int val = sortedQ[i].first;
            int idx = sortedQ[i].second;
            while (!minH.empty() && minH.top()[0] < val) {
                int i = minH.top()[1];
                int j = minH.top()[2];
                minH.pop();
                points++;
                for (const auto& dir: directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !vis[i_][j_]) {
                        minH.push({grid[i_][j_], i_, j_});
                        vis[i_][j_] = true;
                    }
                }
            }
            res[idx] = points;
        }
        return res;
    }
};
