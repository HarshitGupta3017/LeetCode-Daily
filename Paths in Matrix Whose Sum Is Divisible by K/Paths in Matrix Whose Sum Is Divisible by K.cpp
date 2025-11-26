// Solution for Paths in Matrix Whose Sum Is Divisible by K in CPP

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        /*
            DP table:
            dp[i][j][r] = number of ways to reach (m-1, n-1)
                          starting from cell (i, j)
                          with current remainder r (sum % k)
        */
        int dp[m + 1][n + 1][k + 1];
        memset(dp, 0, sizeof(dp));

        /*
            Initialize the base case at the destination cell (m-1, n-1).
            
            For each possible remainder r:
                - Add current cell value ⇒ new remainder = (r + value) % k
                - If divisible by k ⇒ 1 valid path
                - Else ⇒ 0
        */
        for (int rem = 0; rem < k; rem++) {
            int finalRemainder = (rem + grid[m - 1][n - 1]) % k;
            dp[m - 1][n - 1][rem] = (finalRemainder == 0 ? 1 : 0);
        }

        /*
            Fill DP table bottom-up:
            
            Iterate from bottom-right → top-left.
            At each cell (i, j), for each remainder rem:

                updated_rem = (rem + grid[i][j]) % k

                dp[i][j][rem] =
                    ways by going DOWN   (i+1, j)   with updated remainder
                  + ways by going RIGHT (i, j+1)   with updated remainder
        */
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // Skip destination cell (already initialized)
                if (i == m - 1 && j == n - 1) continue;

                for (int rem = 0; rem < k; rem++) {

                    // Add current cell's value to the running remainder
                    int updatedRem = (rem + grid[i][j]) % k;

                    // Move DOWN (if inside bounds)
                    int waysDown = dp[i + 1][j][updatedRem];

                    // Move RIGHT (if inside bounds)
                    int waysRight = dp[i][j + 1][updatedRem];

                    // Total paths from this state
                    dp[i][j][rem] = (waysDown + waysRight) % MOD;
                }
            }
        }

        // Start from (0,0) with initial remainder 0
        return dp[0][0][0];
    }
};
