class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        int mx = 0;
        for (const auto& row: matrix) {
            string pattern = "";
            for (int col = 0; col < matrix[0].size(); col++) {
                pattern += (row[col] == row[0]) ? "O" : "Z";
            }
            mx = max(mx, ++mp[pattern]);
        }
        return mx;
    }
};
