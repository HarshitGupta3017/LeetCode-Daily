// Solution for Maximum Side Length of a Square with Sum Less than or Equal to Threshold in CPP

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int rows = mat.size();
        int cols = mat[0].size();

        /*
            prefix[i][j] stores the sum of all elements
            in the rectangle from (0,0) to (i,j).

            This allows us to compute the sum of any sub-rectangle
            in O(1) time using inclusion–exclusion.
        */
        vector<vector<int>> prefix(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                /*
                    Inclusion–Exclusion principle:
                    Sum till (i,j) =
                    - sum above
                    - sum left
                    - subtract top-left overlap (added twice)
                    + current cell value
                */
                prefix[i][j] =
                    (i > 0 ? prefix[i - 1][j] : 0) +
                    (j > 0 ? prefix[i][j - 1] : 0) -
                    ((i > 0 && j > 0) ? prefix[i - 1][j - 1] : 0) +
                    mat[i][j];
            }
        }

        /*
            Helper lambda to compute the sum of a square/submatrix
            with top-left corner (i, j) and bottom-right corner (r2, c2).

            Uses prefix sums to answer in O(1).
        */
        auto sumOfSquare = [&prefix](int i, int j, int r2, int c2) {

            int sum = prefix[r2][c2];

            // Remove area above the square
            if (i > 0)
                sum -= prefix[i - 1][c2];

            // Remove area to the left of the square
            if (j > 0)
                sum -= prefix[r2][j - 1];

            // Add back top-left overlap (was subtracted twice)
            if (i > 0 && j > 0)
                sum += prefix[i - 1][j - 1];

            return sum;
        };

        /*
            Checks whether there exists at least ONE square
            of given side length whose sum <= threshold.

            WHY boolean check?
            ------------------
            We don't care WHERE the square is.
            We only care IF it exists.

            This gives us a monotonic property needed
            for binary search.
        */
        auto isValid = [&](int side) {
            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {
                    int r2 = i + side - 1;
                    int c2 = j + side - 1;

                    int sum = sumOfSquare(i, j, r2, c2);

                    if (sum <= threshold) return true;
                }
            }
            return false;
        };

        /*
            Binary Search on SIDE LENGTH

            WHY binary search is valid:
            ----------------------------
            If a square of side k is possible,
            then all squares of side < k are also possible.

            If k is NOT possible,
            then any square > k is impossible.

            => Monotonic behavior

            Can apply binary search on the offset - 1 i.e. side values too from previous approach
        */
        int low = 1;
        int high = min(rows, cols);
        int best = 0;  // stores the maximum valid square side length found so far

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid)) {
                best = mid;  // valid, try bigger
                low = mid + 1;
            } else {
                high = mid - 1; // invalid, try smaller
            }
        }
        
        return best;
    }
};
