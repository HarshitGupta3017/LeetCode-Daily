// Solution for Champagne Tower in CPP

class Solution {
public:

    /*
        Recursive DP function.

        Parameters:
        - poured: total cups poured into the top glass
        - row: current row we are computing
        - col: current glass index in that row
        - memo: memoization table

        Returns:
        Total amount of champagne that reaches glass (row, col),
        BEFORE capping at 1.
    */
    double computeAmount(int poured, int row, int col, vector<vector<double>>& memo) {

        // Invalid glass positions
        if (row < 0 || col < 0 || col > row)
            return 0.0;

        // Base case: top glass
        if (row == 0 && col == 0)
            return poured;

        // If already computed, return stored value
        if (memo[row][col] != -1.0)
            return memo[row][col];

        /*
            Champagne reaching current glass
            comes from two glasses above:

            1) (row-1, col-1)
            2) (row-1, col)

            Each contributes half of its overflow.
        */

        double leftParent =
            max(0.0, (computeAmount(poured, row - 1, col - 1, memo) - 1.0) / 2.0);

        double rightParent =
            max(0.0, (computeAmount(poured, row - 1, col, memo) - 1.0) / 2.0);

        // Total amount flowing into current glass
        return memo[row][col] = leftParent + rightParent;
    }

    double champagneTower(int poured, int query_row, int query_glass) {

        /*
            We only need up to 100 rows
            (problem constraint).
        */
        vector<vector<double>> memo(101, vector<double>(101, -1.0));

        /*
            A glass can hold at most 1 cup.
            Even if more reaches it,
            we cap the answer at 1.
        */
        return min(1.0, computeAmount(poured, query_row, query_glass, memo));
    }
};
