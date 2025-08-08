// Solution for Soup Servings in CPP

class Solution {
public:
    // Each pair represents a serving: {amount from A, amount from B}
    vector<pair<int, int>> servingOptions = {
        {100, 0}, {75, 25}, {50, 50}, {25, 75}
    };

    // Memoization table
    vector<vector<double>> dp;

    // Recursive function to compute probability
    double getProbability(double remainingA, double remainingB) {
        // Case: Both soups run out simultaneously
        if (remainingA <= 0 && remainingB <= 0) return 0.5;

        // Case: Soup A runs out first
        if (remainingA <= 0) return 1.0;

        // Case: Soup B runs out first
        if (remainingB <= 0) return 0.0;

        // Check if result already computed
        if (dp[remainingA][remainingB] != -1) return dp[remainingA][remainingB];

        double totalProb = 0.0;

        // Try all 4 serving options (each has 0.25 probability)
        for (const auto& option : servingOptions) {
            int serveA = option.first;
            int serveB = option.second;

            // Recur with reduced amounts
            totalProb += getProbability(remainingA - serveA, remainingB - serveB);
        }

        // Average over the 4 options
        return dp[remainingA][remainingB] = 0.25 * totalProb;
    }

    double soupServings(int n) {
        // Optimization: For large n, the answer converges to 1.0
        if (n >= 5000) return 1.0;

        // Resize DP table to fit possible (A, B) amounts
        dp.resize(n + 1, vector<double>(n + 1, -1.0));

        // Start with full servings of both soups
        return getProbability(n, n);
    }
};
