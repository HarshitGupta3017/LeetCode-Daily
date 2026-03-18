// Solution for Count Submatrices with Top-Left Element and Sum Less Than k in CPP

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int totalRows = grid.size();
        int totalCols = grid[0].size();

        /*
            This will count how many valid submatrices exist
            such that:
            - They start from (0,0)
            - Their sum ≤ k
        */
        int validSubmatrixCount = 0;

        /*
            We convert grid into a PREFIX SUM MATRIX in-place.

            After transformation:
            grid[r][c] = sum of submatrix from (0,0) to (r,c)
        */
        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalCols; col++) {

                /*
                    Add value from top cell
                */
                if (row > 0)
                    grid[row][col] += grid[row - 1][col];

                /*
                    Add value from left cell
                */
                if (col > 0)
                    grid[row][col] += grid[row][col - 1];

                /*
                    Subtract overlap (top-left)
                    to avoid double counting
                */
                if (row > 0 && col > 0)
                    grid[row][col] -= grid[row - 1][col - 1];

                /*
                    Now grid[row][col] represents sum of submatrix:
                    (0,0) → (row,col)
                */

                /*
                    If sum ≤ k → valid submatrix
                */
                if (grid[row][col] <= k) {
                    validSubmatrixCount++;
                }
                else {
                    /*
                        IMPORTANT OPTIMIZATION:

                        Since all values are non-negative,
                        prefix sums increase as we move right.

                        So if current column exceeds k,
                        all further columns in this row will also exceed k.

                        Hence we can safely break.
                    */
                    break;
                }
            }
        }

        return validSubmatrixCount;
    }
};
