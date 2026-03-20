// Solution for Minimum Absolute Difference in Sliding Submatrix in CPP

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Result grid of size (m-k+1) x (n-k+1)
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, 0));

        // Iterate over all top-left corners of k x k submatrices
        for (int rowStart = 0; rowStart <= m - k; rowStart++) {
            for (int colStart = 0; colStart <= n - k; colStart++) {

                // Collect all elements in the current k x k submatrix
                vector<int> submatrixElements;
                for (int r = rowStart; r < rowStart + k; r++) {
                    for (int c = colStart; c < colStart + k; c++) {
                        submatrixElements.push_back(grid[r][c]);
                    }
                }

                // Sort elements to easily find minimum absolute difference
                sort(submatrixElements.begin(), submatrixElements.end());

                int minDiff = INT_MAX;

                // Find the minimum absolute difference between distinct elements
                for (int i = 1; i < submatrixElements.size(); i++) {
                    if (submatrixElements[i] != submatrixElements[i - 1]) {
                        minDiff = min(minDiff, submatrixElements[i] - submatrixElements[i - 1]);
                    }
                }

                // If all elements are the same, minDiff remains INT_MAX → set it to 0
                result[rowStart][colStart] = (minDiff == INT_MAX ? 0 : minDiff);
            }
        }

        return result;
    }
};
