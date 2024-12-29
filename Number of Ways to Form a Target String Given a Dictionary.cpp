class Solution {
public:
    int t[1001][1001];
    const int M = 1e9+7;
    int solve(int i, int j, vector<vector<long long>>& freq, int m, int n, string& target) {
        if (i == n) return 1;
        if (j == m) return 0;
        if (t[i][j] != -1) return t[i][j];
        int take = (freq[target[i] - 'a'][j] * solve(i + 1, j + 1, freq, m, n, target)) % M;
        int notTake = solve(i, j + 1, freq, m, n, target) % M;
        return t[i][j] = (take + notTake) % M;
    }

    int numWays(vector<string>& words, string target) {
        int m = words[0].size(), n = target.size();
        vector<vector<long long>> freq(26, vector<long long>(m));
        for (int col = 0; col < m; col++) {
            for (const auto& word: words) {
                int ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }
        memset(t, -1, sizeof(t));
        return solve(0, 0, freq, m, n, target);
    }
};
