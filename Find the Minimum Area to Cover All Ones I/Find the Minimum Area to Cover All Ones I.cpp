// Solution for Find the Minimum Area to Cover All Ones I in CPP

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int totalRows = grid.size();         // Number of rows in grid
        int totalCols = grid[0].size();      // Number of columns in grid

        // Initialize boundaries of rectangle
        int minRow = totalRows;              // Smallest row index where '1' is found
        int maxRow = -1;                     // Largest row index where '1' is found
        int minCol = totalCols;              // Smallest col index where '1' is found
        int maxCol = -1;                     // Largest col index where '1' is found

        // Traverse through entire grid
        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalCols; col++) {
                if (grid[row][col] == 1) {   // Whenever we find '1'
                    minRow = min(minRow, row);   // Update smallest row boundary
                    maxRow = max(maxRow, row);   // Update largest row boundary
                    minCol = min(minCol, col);   // Update smallest col boundary
                    maxCol = max(maxCol, col);   // Update largest col boundary
                }
            }
        }

        // Area of rectangle = (height) * (width)
        // Height = (maxRow - minRow + 1)
        // Width  = (maxCol - minCol + 1)
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
