// Solution for Minimum Score Triangulation of Polygon in CPP

    class Solution {
    public:
        // Recursive DP function to find minimum triangulation score
        int solve(vector<int>& polygon, int left, int right, vector<vector<int>>& dp) {
            // Base case: less than 2 edges means no triangle can be formed
            if (right - left + 1 < 3) {
                return 0;
            }

            // Return memoized result if already computed
            if (dp[left][right] != -1) {
                return dp[left][right];
            }

            int minScore = INT_MAX;

            // Try all possible "middle" points to form a triangle (left, k, right)
            for (int k = left + 1; k < right; k++) {
                // Score of the current triangle
                int triangleScore = polygon[left] * polygon[right] * polygon[k];

                // Total score = score of this triangle + subproblems
                int totalScore = solve(polygon, left, k, dp) 
                            + triangleScore 
                            + solve(polygon, k, right, dp);

                minScore = min(minScore, totalScore);
            }

            // Store result in memo table
            return dp[left][right] = minScore;
        }

        int minScoreTriangulation(vector<int>& values) {
            int n = values.size();

            // Memoization table initialized with -1
            vector<vector<int>> dp(n, vector<int>(n, -1));

            // Compute result for the full polygon (0 to n-1)
            return solve(values, 0, n - 1, dp);
        }
    };
