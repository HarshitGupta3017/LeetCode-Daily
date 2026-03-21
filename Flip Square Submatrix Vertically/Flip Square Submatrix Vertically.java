// Solution for Flip Square Submatrix Vertically in JAVA

class Solution {
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {

        // Define boundaries
        int topRow = x;
        int bottomRow = x + k - 1;
        int leftCol = y;
        int rightCol = y + k - 1;

        // Swap rows until pointers meet
        while (topRow < bottomRow) {

            for (int col = leftCol; col <= rightCol; col++) {
                int temp = grid[topRow][col];
                grid[topRow][col] = grid[bottomRow][col];
                grid[bottomRow][col] = temp;
            }

            topRow++;
            bottomRow--;
        }

        return grid;
    }
}
