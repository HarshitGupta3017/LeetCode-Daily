class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> seen(n * n + 1, false);
        vector<int> res(2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (seen[grid[i][j]] == true) res[0] = grid[i][j];
                seen[grid[i][j]] = true;
            }
        }
        for (int i = 1; i < n * n + 1; i++) {
            if (seen[i] == false) res[1] = i;
        }
        return res;
    }
};
