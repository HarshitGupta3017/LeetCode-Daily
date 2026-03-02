// Solution for Minimum Swaps to Arrange a Binary Grid in JAVA

class Solution {
    public int minSwaps(int[][] grid) {

        int n = grid.length;
        int[] trailingZeros = new int[n];

        // Step 1: Count trailing zeros for each row
        for (int row = 0; row < n; row++) {

            int zeroCount = 0;

            for (int col = n - 1; col >= 0 && grid[row][col] == 0; col--) {
                zeroCount++;
            }

            trailingZeros[row] = zeroCount;
        }

        int totalSwaps = 0;

        // Step 2: Fix row by row
        for (int targetRow = 0; targetRow < n; targetRow++) {

            int requiredZeros = n - targetRow - 1;

            int candidateRow = targetRow;

            while (candidateRow < n &&
                   trailingZeros[candidateRow] < requiredZeros) {
                candidateRow++;
            }

            if (candidateRow == n)
                return -1;

            // Bubble up
            while (candidateRow > targetRow) {

                int temp = trailingZeros[candidateRow];
                trailingZeros[candidateRow] =
                        trailingZeros[candidateRow - 1];
                trailingZeros[candidateRow - 1] = temp;

                candidateRow--;
                totalSwaps++;
            }
        }

        return totalSwaps;
    }
}
