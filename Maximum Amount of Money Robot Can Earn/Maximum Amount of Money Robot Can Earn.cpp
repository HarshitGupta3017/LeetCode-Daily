// Solution for Maximum Amount of Money Robot Can Earn in CPP

class Solution {
public:

    /*
        DP State:
        dp[row][col][remainingNeutralizations]

        Meaning:
        Maximum coins we can collect starting from (row, col)
        with 'remainingNeutralizations' robber neutralizations left
    */

    int dfs(vector<vector<int>>& coins,
            int row, int col,
            int rows, int cols,
            int remainingNeutralizations,
            vector<vector<vector<int>>>& dp) {

        /*
            BASE CASE:
            Reached destination cell
        */
        if (row == rows - 1 && col == cols - 1) {

            // If it's a robber cell and we can neutralize → take 0 instead of loss
            if (coins[row][col] < 0 && remainingNeutralizations > 0)
                return 0;

            return coins[row][col];
        }

        /*
            OUT OF BOUNDS → invalid path
        */
        if (row >= rows || col >= cols) {
            return INT_MIN;
        }

        /*
            MEMOIZATION CHECK
        */
        if (dp[row][col][remainingNeutralizations] != INT_MIN) {
            return dp[row][col][remainingNeutralizations];
        }

        /*
        ============================================================
        OPTION 1: TAKE current cell normally
        ============================================================

        → Add coins[row][col]
        → Move right or down
        */
        int goDown  = dfs(coins, row + 1, col, rows, cols, remainingNeutralizations, dp);
        int goRight = dfs(coins, row, col + 1, rows, cols, remainingNeutralizations, dp);

        int takeCurrent = coins[row][col] + max(goDown, goRight);

        /*
        ============================================================
        OPTION 2: NEUTRALIZE robber (only if negative cell)
        ============================================================

        → Skip the negative impact
        → Use one neutralization
        */
        int neutralize = INT_MIN;

        if (coins[row][col] < 0 && remainingNeutralizations > 0) {

            int neutralizeDown  = dfs(coins, row + 1, col, rows, cols, remainingNeutralizations - 1, dp);
            int neutralizeRight = dfs(coins, row, col + 1, rows, cols, remainingNeutralizations - 1, dp);

            neutralize = max(neutralizeDown, neutralizeRight);
        }

        /*
            Store best result
        */
        return dp[row][col][remainingNeutralizations] = max(takeCurrent, neutralize);
    }

    int maximumAmount(vector<vector<int>>& coins) {

        int rows = coins.size();
        int cols = coins[0].size();

        /*
            Initialize DP with INT_MIN
            → Represents "uncomputed"
        */
        vector<vector<vector<int>>> dp(
            rows,
            vector<vector<int>>(cols, vector<int>(3, INT_MIN))
        );

        /*
            Start from (0,0) with 2 neutralizations available
        */
        return dfs(coins, 0, 0, rows, cols, 2, dp);
    }
};
