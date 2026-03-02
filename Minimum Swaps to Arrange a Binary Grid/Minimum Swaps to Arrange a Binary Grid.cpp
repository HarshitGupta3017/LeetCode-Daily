// Solution for Minimum Swaps to Arrange a Binary Grid in CPP

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int n = grid.size();

        /*
            Step 1:
            Convert 2D grid into a 1D array.

            trailingZeros[i] =
            number of consecutive zeros at the END of row i.
        */
        vector<int> trailingZeros(n);

        for (int row = 0; row < n; row++) {

            int zeroCount = 0;

            // Count zeros from right side
            for (int col = n - 1; col >= 0 && grid[row][col] == 0; col--) {
                zeroCount++;
            }

            trailingZeros[row] = zeroCount;
        }

        /*
            Step 2:
            Try to fix row by row using greedy.

            For row i:
            We need at least (n - i - 1) trailing zeros.
        */
        int totalSwaps = 0;

        for (int targetRow = 0; targetRow < n; targetRow++) {

            int requiredZeros = n - targetRow - 1;

            /*
                Find first row below (including current)
                that satisfies trailingZeros >= requiredZeros
            */
            int candidateRow = targetRow;

            while (candidateRow < n && trailingZeros[candidateRow] < requiredZeros) {
                candidateRow++;
            }

            /*
                If no such row exists → impossible.
            */
            if (candidateRow == n) {
                return -1;
            }

            /*
                Bring candidateRow up to targetRow
                using adjacent swaps.

                Each upward movement costs 1 swap.
            */
            while (candidateRow > targetRow) {

                swap(trailingZeros[candidateRow], trailingZeros[candidateRow - 1]);

                candidateRow--;
                totalSwaps++;
            }
        }

        return totalSwaps;
    }
};
