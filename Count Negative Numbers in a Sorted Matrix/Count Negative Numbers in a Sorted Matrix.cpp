// Solution for Count Negative Numbers in a Sorted Matrix in CPP

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();

        int negativeCount = 0;

        // Start from bottom-left corner of the matrix
        int row = totalRows - 1;
        int col = 0;

        // Traverse until we go out of matrix bounds
        while (row >= 0 && col < totalCols) {

            // If current value is negative:
            // → all elements to the right in this row are also negative
            if (grid[row][col] < 0) {
                negativeCount += (totalCols - col);
                row--;  // move one row up
            }
            // If current value is non-negative:
            // → move right to find the first negative element
            else {
                col++;
            }
        }

        return negativeCount;
    }
};
