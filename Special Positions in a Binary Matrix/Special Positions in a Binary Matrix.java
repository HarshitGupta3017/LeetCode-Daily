// Solution for Special Positions in a Binary Matrix in JAVA

class Solution {
    public int numSpecial(int[][] mat) {

        int totalRows = mat.length;
        int totalColumns = mat[0].length;

        int[] rowOnesCount = new int[totalRows];
        int[] columnOnesCount = new int[totalColumns];

        // First pass: count 1s in each row and column
        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalColumns; col++) {
                if (mat[row][col] == 1) {
                    rowOnesCount[row]++;
                    columnOnesCount[col]++;
                }
            }
        }

        // Second pass: check special positions
        int specialPositionsCount = 0;

        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalColumns; col++) {
                if (mat[row][col] == 1 &&
                    rowOnesCount[row] == 1 &&
                    columnOnesCount[col] == 1) {

                    specialPositionsCount++;
                }
            }
        }

        return specialPositionsCount;
    }
}
