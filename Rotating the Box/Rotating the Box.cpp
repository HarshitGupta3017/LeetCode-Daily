// Solution for Rotating the Box in CPP

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        
        // Number of rows (height of the box before rotation)
        int originalRows = boxGrid.size();
        
        // Number of columns (width of the box before rotation)
        int originalCols = boxGrid[0].size();

        // After a 90° clockwise rotation:
        // - rows become columns
        // - columns become rows
        // So new matrix size = originalCols x originalRows
        vector<vector<char>> rotatedBox(originalCols, vector<char>(originalRows));

        // -------------------------------
        // STEP 1: Rotate the matrix
        // -------------------------------
        // Mapping rule for 90° clockwise rotation:
        // boxGrid[i][j] → rotatedBox[j][originalRows - i - 1]
        //
        // Why this works:
        // - Column index becomes new row
        // - Row index is reversed to simulate rotation
        for (int row = 0; row < originalRows; row++) {
            for (int col = 0; col < originalCols; col++) {
                rotatedBox[col][originalRows - row - 1] = boxGrid[row][col];
            }
        }

        // -------------------------------
        // STEP 2: Apply gravity
        // -------------------------------
        // After rotation, stones '#' should fall downward.
        // We simulate gravity column by column.
        //
        // Important idea:
        // We track the lowest available position where a stone can fall
        // using a pointer (emptyRowPointer).
        //
        // We process from bottom → top because gravity pulls downward.
        for (int col = 0; col < originalRows; col++) {

            // This pointer tells us the next free position from the bottom
            // where a stone can settle.
            int emptyRowPointer = originalCols - 1;

            // Traverse from bottom row to top row
            for (int row = originalCols - 1; row >= 0; row--) {

                // Case 1: Obstacle '*'
                if (rotatedBox[row][col] == '*') {
                    // Obstacle blocks falling stones
                    // So reset the pointer to just above this obstacle
                    emptyRowPointer = row - 1;
                    continue;
                }

                // Case 2: Stone '#'
                if (rotatedBox[row][col] == '#') {
                    // Remove stone from current position
                    rotatedBox[row][col] = '.';

                    // Place stone at the lowest available position
                    rotatedBox[emptyRowPointer][col] = '#';

                    // Move pointer one step upward for next stone
                    emptyRowPointer--;
                }

                // Case 3: Empty '.' → do nothing
            }
        }

        // Final transformed box
        return rotatedBox;
    }
};
