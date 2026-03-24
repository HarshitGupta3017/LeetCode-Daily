// Solution for Construct Product Matrix in CPP

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        const int MOD = 12345;

        int rows = grid.size();
        int cols = grid[0].size();

        /*
            Result matrix where:
            result[i][j] = product of ALL elements except grid[i][j]
        */
        vector<vector<int>> result(rows, vector<int>(cols));

        /*
            STEP 1: Compute suffix products

            We traverse from bottom-right → top-left

            suffixProduct stores:
            product of all elements AFTER current cell (in flattened order)

            So:
            result[i][j] = suffix of remaining elements
        */
        long long suffixProduct = 1;

        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {

                // Store suffix product before including current cell
                result[r][c] = suffixProduct;

                // Update suffix including current cell
                suffixProduct = (suffixProduct * grid[r][c]) % MOD;
            }
        }

        /*
            STEP 2: Multiply with prefix products

            Now we traverse from top-left → bottom-right

            prefixProduct stores:
            product of all elements BEFORE current cell

            So:
            final result = prefix * suffix
        */
        long long prefixProduct = 1;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // Combine prefix (before) and suffix (after)
                result[r][c] = (prefixProduct * result[r][c]) % MOD;

                // Update prefix including current cell
                prefixProduct = (prefixProduct * grid[r][c]) % MOD;
            }
        }

        return result;
    }
};
