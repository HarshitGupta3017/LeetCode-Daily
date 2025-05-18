// Solution for Painting a Grid With Three Different Colors in CPP

class Solution {
public:
    vector<string> columnStates;
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    void generateColumnStates(string curr, char prevChar, int l, int m) {
        if (l == m) {
            columnStates.push_back(curr);
            return;
        }
        for (char currColor: {'R', 'G', 'B'}) {
            if (currColor == prevChar)
                continue;
            generateColumnStates(curr + currColor, currColor, l + 1, m);
        }
    }

    int solve(int remainCols, int prevIdx, int m) {
        if (remainCols == 0) {
            return 1;
        }
        if (dp[remainCols][prevIdx] != -1) {
            return dp[remainCols][prevIdx];
        }
        int ways = 0;
        string prevState = columnStates[prevIdx];
        for (int i = 0; i < columnStates.size(); i++) {
            if (i == prevIdx)
                continue;
            string currState = columnStates[i];
            bool valid = true;
            for (int j = 0; j < m; j++) {
                if (prevState[j] == currState[j]) {
                    valid = false;
                }
            }
            if (valid) {
                ways = (ways + solve(remainCols - 1, i, m)) % MOD;
            }
        }
        return dp[remainCols][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        // generateColumnStates(current string, previous character, length, m (row size)) 
        generateColumnStates("", '#', 0, m);
        int totalStates = columnStates.size();
        dp = vector<vector<int>>(n + 1, vector<int>(totalStates + 1, -1));
        int result = 0;
        for (int i = 0; i < columnStates.size(); i++) {
            result = (result + solve(n - 1, i, m)) % MOD;
        }
        return result;
    }
};
