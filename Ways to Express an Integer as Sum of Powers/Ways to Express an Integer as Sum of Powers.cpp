// Solution for Ways to Express an Integer as Sum of Powers in CPP

class Solution {
public:
    const int MOD = 1e9 + 7; // Modulo for large results

    // Recursive helper function with memoization
    int countWays(int remainingSum, int currentBase, int power, vector<vector<int>>& dp) {
        // Base case 1: exact sum reached → valid combination
        if (remainingSum == 0) {
            return 1;
        }

        // Base case 2: sum exceeded → invalid path
        if (remainingSum < 0) {
            return 0;
        }

        // Calculate currentBase^power
        int currentValue = pow(currentBase, power);

        // Base case 3: if currentValue exceeds remainingSum, we can't use it or any larger number
        if (currentValue > remainingSum) {
            return 0;
        }

        // Check memo table
        if (dp[remainingSum][currentBase] != -1) {
            return dp[remainingSum][currentBase];
        }

        // Option 1: include currentBase in the sum
        int takeOption = countWays(remainingSum - currentValue, currentBase + 1, power, dp);

        // Option 2: skip currentBase and move to next integer
        int skipOption = countWays(remainingSum, currentBase + 1, power, dp);

        // Store result in dp table and return
        return dp[remainingSum][currentBase] = (takeOption + skipOption) % MOD;
    }

    int numberOfWays(int n, int x) {
        // dp[remainingSum][currentBase] → number of ways to make remainingSum starting with currentBase
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return countWays(n, 1, x, dp); // Start with sum = n, first base = 1
    }
};
