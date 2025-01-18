class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        minHeap.push({0, 0, 0});
        res[0][0] = 0;
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int currCost = curr[0], i = curr[1], j = curr[2];
            if (res[i][j] < currCost) continue;
            for (int k = 0; k <= 3; k++) {
                int i_ = i + dir[k][0];
                int j_ = j + dir[k][1];
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    int newCost = currCost + ((grid[i][j] - 1 != k) ? 1 : 0);
                    if (newCost < res[i_][j_]) {
                        res[i_][j_] = newCost;
                        minHeap.push({newCost, i_, j_});
                    }
                }
            }
        }
        return res[m - 1][n - 1];
    }   
};
