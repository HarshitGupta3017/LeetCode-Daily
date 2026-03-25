// Solution for Equal Sum Grid Partition I in CPP

class Solution {
public:

    using ll = long long;

    bool canPartitionGrid(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        /*
            STEP 1: Compute total sum + rowSum + colSum
        */
        ll totalSum = 0;

        vector<ll> rowSum(rows, 0);
        vector<ll> colSum(cols, 0);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                totalSum += grid[r][c];
                rowSum[r] += grid[r][c];
                colSum[c] += grid[r][c];
            }
        }

        /*
            If total sum is odd → equal partition impossible
        */
        if (totalSum % 2 != 0) return false;

        /*
        ===========================
        CHECK 1: Horizontal Cut
        ===========================

        Try splitting after each row:
        Top part → rows [0...r]
        Bottom part → rows [r+1...end]
        */
        ll topSum = 0;

        for (int r = 0; r < rows - 1; r++) { // ensure bottom part exists

            topSum += rowSum[r];

            /*
                Instead of computing bottomSum,
                we compare with totalSum / 2
            */
            if (topSum * 2 == totalSum) return true;
        }

        /*
        ===========================
        CHECK 2: Vertical Cut
        ===========================

        Try splitting after each column:
        Left part → cols [0...c]
        Right part → cols [c+1...end]
        */
        ll leftSum = 0;

        for (int c = 0; c < cols - 1; c++) { // ensure right part exists

            leftSum += colSum[c];

            if (leftSum * 2 == totalSum) return true;
        }

        /*
            No valid partition found
        */
        return false;
    }
};
