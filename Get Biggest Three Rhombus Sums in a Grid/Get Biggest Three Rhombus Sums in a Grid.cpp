// Solution for Get Biggest Three Rhombus Sums in a Grid in CPP

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        /*
            Set used to store the largest 3 distinct rhombus sums.
            We keep the set size ≤ 3 by removing the smallest element.
        */
        set<int> largestThreeSums;

        /*
            diagonalPrefixRight:
            Prefix sums along the top-left → bottom-right direction
            (↘ diagonal)

            diagonalPrefixLeft:
            Prefix sums along the top-right → bottom-left direction
            (↙ diagonal)
        */
        vector<vector<int>> diagonalPrefixRight(rows, vector<int>(cols, 0));
        vector<vector<int>> diagonalPrefixLeft(rows, vector<int>(cols, 0));

        /*
            Build diagonal prefix sums.
            These allow us to compute rhombus edges in O(1).
        */
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // Build ↘ diagonal prefix
                diagonalPrefixRight[r][c] = grid[r][c];
                if (r - 1 >= 0 && c - 1 >= 0)
                    diagonalPrefixRight[r][c] += diagonalPrefixRight[r - 1][c - 1];

                // Build ↙ diagonal prefix
                diagonalPrefixLeft[r][c] = grid[r][c];
                if (r - 1 >= 0 && c + 1 < cols)
                    diagonalPrefixLeft[r][c] += diagonalPrefixLeft[r - 1][c + 1];
            }
        }

        /*
            Helper function to maintain only the 3 largest distinct sums.
        */
        auto insertSum = [&](int sumValue) {

            largestThreeSums.insert(sumValue);

            if (largestThreeSums.size() > 3) {
                // remove smallest element
                largestThreeSums.erase(begin(largestThreeSums));
            }
        };

        /*
            Try every cell as the CENTER of a rhombus.
        */
        for (int centerRow = 0; centerRow < rows; centerRow++) {
            for (int centerCol = 0; centerCol < cols; centerCol++) {

                /*
                    Area = 0 rhombus (single cell)
                */
                insertSum(grid[centerRow][centerCol]);

                /*
                    Try expanding rhombus side length.
                */
                for (int side = 1;
                     centerRow - side >= 0 &&
                     centerRow + side < rows &&
                     centerCol - side >= 0 &&
                     centerCol + side < cols;
                     side++) {

                    int sum = 0;

                    /*
                        Identify the 4 vertices of the rhombus
                    */
                    int topRow = centerRow - side, topCol = centerCol;
                    int rightRow = centerRow, rightCol = centerCol + side;
                    int bottomRow = centerRow + side, bottomCol = centerCol;
                    int leftRow = centerRow, leftCol = centerCol - side;

                    /*
                        Edge 1: Top → Right  (↘ diagonal)
                    */
                    sum += diagonalPrefixRight[rightRow][rightCol];
                    if (topRow - 1 >= 0 && topCol - 1 >= 0)
                        sum -= diagonalPrefixRight[topRow - 1][topCol - 1];

                    /*
                        Edge 2: Right → Bottom (↙ diagonal)
                    */
                    sum += diagonalPrefixLeft[bottomRow][bottomCol];
                    if (rightRow - 1 >= 0 && rightCol + 1 < cols)
                        sum -= diagonalPrefixLeft[rightRow - 1][rightCol + 1];

                    /*
                        Edge 3: Bottom → Left (↘ diagonal)
                    */
                    sum += diagonalPrefixRight[bottomRow][bottomCol];
                    if (leftRow - 1 >= 0 && leftCol - 1 >= 0)
                        sum -= diagonalPrefixRight[leftRow - 1][leftCol - 1];

                    /*
                        Edge 4: Left → Top (↙ diagonal)
                    */
                    sum += diagonalPrefixLeft[leftRow][leftCol];
                    if (topRow - 1 >= 0 && topCol + 1 < cols)
                        sum -= diagonalPrefixLeft[topRow - 1][topCol + 1];

                    /*
                        Each vertex gets counted twice when adding edges.
                        So we subtract them once to fix double counting.
                    */
                    sum -= grid[topRow][topCol];
                    sum -= grid[rightRow][rightCol];
                    sum -= grid[bottomRow][bottomCol];
                    sum -= grid[leftRow][leftCol];

                    insertSum(sum);
                }
            }
        }

        /*
            Convert set → vector in descending order
        */
        return vector<int>(rbegin(largestThreeSums), rend(largestThreeSums));
    }
};
