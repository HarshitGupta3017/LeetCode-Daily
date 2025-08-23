// Solution for Find the Minimum Area to Cover All Ones II in CPP

class Solution {
public:

    // ✅ Function to compute the bounding rectangle area of all 1's 
    // inside the given subgrid defined by (rowStart,rowEnd) and (colStart,colEnd)
    // same function code as part 1 of this problem
    int computeBoundingArea(int rowStart, int rowEnd, int colStart, int colEnd, vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();

        // Initialize boundaries
        int minRow = totalRows, maxRow = -1;
        int minCol = totalCols, maxCol = -1;

        // Scan subgrid for 1's
        for (int r = rowStart; r < rowEnd; r++) {
            for (int c = colStart; c < colEnd; c++) {
                if (grid[r][c] == 1) {
                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);
                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);
                }
            }
        }

        // If no 1’s found in subgrid → return 0 area
        if (maxRow == -1) return 0;

        // Rectangle area = height * width
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    // ✅ Main helper function: tries all possible splits into 3 rectangles
    int computeMinAreaSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int minAreaSum = INT_MAX;

        // 🔹 CASE 1 & 2: Split into 1 horizontal + 2 vertical rectangles OR 2 horizontal + 1 vertical
        for (int rowSplit = 1; rowSplit < rows; rowSplit++) {
            for (int colSplit = 1; colSplit < cols; colSplit++) {
                
                // Case 1: Top rectangle, bottom-left rectangle, bottom-right rectangle
                int topArea = computeBoundingArea(0, rowSplit, 0, cols, grid);
                int bottomLeftArea = computeBoundingArea(rowSplit, rows, 0, colSplit, grid);
                int bottomRightArea = computeBoundingArea(rowSplit, rows, colSplit, cols, grid);
                minAreaSum = min(minAreaSum, topArea + bottomLeftArea + bottomRightArea);

                // Case 2: Top-left rectangle, top-right rectangle, bottom rectangle
                int topLeftArea = computeBoundingArea(0, rowSplit, 0, colSplit, grid);
                int topRightArea = computeBoundingArea(0, rowSplit, colSplit, cols, grid);
                int bottomArea = computeBoundingArea(rowSplit, rows, 0, cols, grid);
                minAreaSum = min(minAreaSum, topLeftArea + topRightArea + bottomArea);
            }
        }

        // 🔹 CASE 3: Split into 3 horizontal strips
        for (int rowSplit1 = 1; rowSplit1 < rows; rowSplit1++) {
            for (int rowSplit2 = rowSplit1 + 1; rowSplit2 < rows; rowSplit2++) {
                int topArea = computeBoundingArea(0, rowSplit1, 0, cols, grid);
                int middleArea = computeBoundingArea(rowSplit1, rowSplit2, 0, cols, grid);
                int bottomArea = computeBoundingArea(rowSplit2, rows, 0, cols, grid);
                minAreaSum = min(minAreaSum, topArea + middleArea + bottomArea);
            }
        }

        return minAreaSum;
    }

    // ✅ Rotate grid 90 degrees clockwise (to try splitting vertically as well)
    vector<vector<int>> rotateClockwise(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> rotated(cols, vector<int>(rows));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                rotated[c][rows - r - 1] = grid[r][c];
            }
        }
        return rotated;
    }

    // ✅ Main function
    int minimumSum(vector<vector<int>>& grid) {
        int result = computeMinAreaSum(grid);

        // Try again on rotated grid (to cover all orientations)
        vector<vector<int>> rotatedGrid = rotateClockwise(grid);
        result = min(result, computeMinAreaSum(rotatedGrid));

        return result;
    }
};
