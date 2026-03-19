// Solution for Count Submatrices With Equal Frequency of X and Y in CPP

class Solution {
public:

    /*
        We store:
        first  -> count of 'X'
        second -> count of 'Y'
    */
    using Pair = pair<int, int>;

    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int totalRows = grid.size();
        int totalCols = grid[0].size();

        /*
            prefixSum[r][c] stores:
            {
                total X's in rectangle (0,0) → (r,c),
                total Y's in rectangle (0,0) → (r,c)
            }
        */
        vector<vector<Pair>> prefixSum(totalRows, vector<Pair>(totalCols, {0, 0}));

        int validSubmatrixCount = 0;

        /*
            We only consider submatrices that:
            - MUST include (0,0)
            So every valid submatrix is of form:
                (0,0) → (r,c)
        */
        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalCols; col++) {

                /*
                    Step 1: Add current cell contribution
                */
                if (grid[row][col] == 'X') {
                    prefixSum[row][col].first += 1;
                }
                else if (grid[row][col] == 'Y') {
                    prefixSum[row][col].second += 1;
                }

                /*
                    Step 2: Add from top
                */
                if (row > 0) {
                    prefixSum[row][col].first  += prefixSum[row - 1][col].first;
                    prefixSum[row][col].second += prefixSum[row - 1][col].second;
                }

                /*
                    Step 3: Add from left
                */
                if (col > 0) {
                    prefixSum[row][col].first  += prefixSum[row][col - 1].first;
                    prefixSum[row][col].second += prefixSum[row][col - 1].second;
                }

                /*
                    Step 4: Remove double-counted overlap
                */
                if (row > 0 && col > 0) {
                    prefixSum[row][col].first  -= prefixSum[row - 1][col - 1].first;
                    prefixSum[row][col].second -= prefixSum[row - 1][col - 1].second;
                }

                /*
                    Now prefixSum[row][col] represents:
                    submatrix (0,0) → (row,col)
                */

                int countX = prefixSum[row][col].first;
                int countY = prefixSum[row][col].second;

                /*
                    Condition 1: equal number of X and Y
                    Condition 2: at least one X (so > 0)
                */
                if (countX == countY && countX > 0) {
                    validSubmatrixCount++;
                }
            }
        }

        return validSubmatrixCount;
    }
};
