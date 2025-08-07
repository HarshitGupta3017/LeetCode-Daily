// Solution for Find the Maximum Number of Fruits Collected in CPP

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        // Temporary matrix to store processed values
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int maxFruits = 0;

        // Step 1: Collect diagonal fruits (Child 1's path)
        for (int i = 0; i < n; i++) {
            maxFruits += fruits[i][i];  // Collect fruits from (i, i)
        }

        // Step 2: Prepare dp matrix for child 2 and child 3 by nullifying unreachable cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Cells that can't be visited by child 2 or child 3
                if ((i < j && i + j < n - 1) || (i > j && i + j < n - 1)) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = fruits[i][j];
                }
            }
        }

        // Step 3: Child 2 collects fruits (above the main diagonal: i < j)
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int fromTopLeft = (j - 1 >= 0) ? dp[i - 1][j - 1] : 0;
                int fromTop = dp[i - 1][j];
                int fromTopRight = (j + 1 < n) ? dp[i - 1][j + 1] : 0;

                dp[i][j] += max({fromTopLeft, fromTop, fromTopRight});
            }
        }

        // Step 4: Child 3 collects fruits (below the main diagonal: i > j)
        for (int j = 1; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                int fromTopLeft = (i - 1 >= 0 && j - 1 >= 0) ? dp[i - 1][j - 1] : 0;
                int fromLeft = dp[i][j - 1];
                int fromBottomLeft = (i + 1 < n && j - 1 >= 0) ? dp[i + 1][j - 1] : 0;

                dp[i][j] += max({fromTopLeft, fromLeft, fromBottomLeft});
            }
        }

        // Step 5: Add the fruits collected by child 2 and 3 from last positions
        return maxFruits + dp[n - 2][n - 1] + dp[n - 1][n - 2];
    }
};
