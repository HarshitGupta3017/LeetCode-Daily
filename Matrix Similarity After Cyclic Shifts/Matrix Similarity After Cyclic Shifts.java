// Solution for Matrix Similarity After Cyclic Shifts in JAVA

class Solution {
    public boolean areSimilar(int[][] matrix, int k) {
        int totalRows = matrix.length;
        int totalCols = matrix[0].length;

        // Normalize k
        k = k % totalCols;

        if (k == 0) return true;

        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalCols; col++) {

                int shiftedIndex;

                // Odd row → shift right
                if (row % 2 == 1) {
                    shiftedIndex = (col - k + totalCols) % totalCols;
                } 
                // Even row → shift left
                else {
                    shiftedIndex = (col + k) % totalCols;
                }

                if (matrix[row][col] != matrix[row][shiftedIndex]) {
                    return false;
                }
            }
        }

        return true;
    }
}
