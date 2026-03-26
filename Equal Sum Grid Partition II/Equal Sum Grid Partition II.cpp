// Solution for Equal Sum Grid Partition II in CPP

class Solution {
public:

    using ll = long long;

    /*
        This function checks if a VALID horizontal cut exists.

        Idea:
        - We keep adding rows to the TOP section.
        - Remaining rows automatically form the BOTTOM section.
        - At each cut:
            topSum vs bottomSum

        We check:
        1. Already equal → valid
        2. Can we remove ONE cell (value = diff) to balance?
    */
    bool check(vector<vector<int>>& grid, ll& totalSum) {

        int rows = grid.size();
        int cols = grid[0].size();

        unordered_set<ll> topSectionValues; // stores all values present in top section
        ll topSum = 0;                      // sum of top section

        /*
            Try every possible horizontal cut
            (cut after row 'r')
        */
        for (int r = 0; r < rows - 1; r++) {

            /*
                Expand top section by including row 'r'
            */
            for (int c = 0; c < cols; c++) {
                topSectionValues.insert(grid[r][c]);
                topSum += grid[r][c];
            }

            ll bottomSum = totalSum - topSum;

            /*
                Case 1: Perfect split
            */
            ll diff = topSum - bottomSum;
            if (diff == 0) return true;

            /*
                Case 2: Try removing ONE cell to balance

                If diff > 0:
                    topSum > bottomSum
                    → remove 'diff' from TOP

                If diff < 0:
                    bottomSum > topSum
                    → remove '-diff' from BOTTOM
            */

            /*
                Special edge checks (boundary cells)
                These ensure connectivity is preserved
            */
            if (diff == grid[0][0]) return true;
            if (diff == grid[0][cols - 1]) return true;
            if (diff == grid[r][0]) return true;

            /*
                General case:
                If top section has more than 1 row and more than 1 column,
                we can safely remove any internal element without breaking connectivity.
            */
            if (r > 0 && cols > 1 && topSectionValues.count(diff)) {
                return true;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        /*
            STEP 1: Compute total sum of grid
        */
        ll totalSum = 0;
        for (const auto& row : grid) {
            totalSum += accumulate(row.begin(), row.end(), 0LL);
        }

        /*
            STEP 2: Try horizontal cuts
        */
        if (check(grid, totalSum)) {
            return true;
        }

        /*
            Reverse rows:
            → helps simulate removing from bottom section
        */
        reverse(grid.begin(), grid.end());

        if (check(grid, totalSum)) {
            return true;
        }

        // Restore original grid
        reverse(grid.begin(), grid.end());

        /*
            STEP 3: Convert vertical cuts → horizontal cuts using transpose
        */
        vector<vector<int>> transposed(cols, vector<int>(rows));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                transposed[c][r] = grid[r][c];
            }
        }

        if (check(transposed, totalSum)) {
            return true;
        }

        /*
            Reverse again for opposite side handling
        */
        reverse(transposed.begin(), transposed.end());

        if (check(transposed, totalSum)) {
            return true;
        }

        return false;
    }
};
