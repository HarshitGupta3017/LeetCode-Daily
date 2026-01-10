// Solution for Minimum ASCII Delete Sum for Two Strings in CPP

class Solution {
public:

    /*
        Returns the minimum ASCII delete sum required to make
        s1[i ... end] and s2[j ... end] equal.
    */
    int solve(int i, int j, string& s1, string& s2, int m, int n,
              vector<vector<int>>& dp) {

        // If both strings are fully processed, no cost needed
        if (i >= m && j >= n) {
            return 0;
        }

        // If s1 is exhausted, we must delete all remaining characters of s2
        if (i >= m) {
            return s2[j] + solve(i, j + 1, s1, s2, m, n, dp);
        }

        // If s2 is exhausted, we must delete all remaining characters of s1
        if (j >= n) {
            return s1[i] + solve(i + 1, j, s1, s2, m, n, dp);
        }

        // Return cached result if already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // If current characters match, no deletion required
        // Move both pointers forward
        if (s1[i] == s2[j]) {
            return dp[i][j] =
                   solve(i + 1, j + 1, s1, s2, m, n, dp);
        }

        // Option 1: delete s1[i] and pay its ASCII value
        int deleteFromS1 =
            s1[i] + solve(i + 1, j, s1, s2, m, n, dp);

        // Option 2: delete s2[j] and pay its ASCII value
        int deleteFromS2 =
            s2[j] + solve(i, j + 1, s1, s2, m, n, dp);

        // Choose the minimum cost option
        return dp[i][j] = min(deleteFromS1, deleteFromS2);
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        // dp[i][j] stores minimum delete sum for s1[i:] and s2[j:]
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, s1, s2, m, n, dp);
    }
};
