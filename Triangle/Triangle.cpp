// Solution for Triangle in CPP

// For better understanding, visualize by writing it in the notebook

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Create a DP table initialized with the last row of the triangle
        vector<int> dp(triangle.back());  // copy the last row
        
        // Start from the second last row and move upwards to the top
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                // For each element, the min path sum is the value at triangle[row][col]
                // plus the minimum of the two adjacent numbers in the row below
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        
        // After processing, dp[0] will contain the minimum path sum from top to bottom
        return dp[0];
    }
};
