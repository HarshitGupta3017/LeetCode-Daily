// Solution for Largest Submatrix With Rearrangements in JAVA

class Solution {
    public int largestSubmatrix(int[][] matrix) {

        int totalRows = matrix.length;
        int totalCols = matrix[0].length;

        int maximumArea = 0;

        // Stores (height, columnIndex)
        List<int[]> previousRowHeights = new ArrayList<>();

        for (int row = 0; row < totalRows; row++) {

            List<int[]> currentRowHeights = new ArrayList<>();
            boolean[] columnVisited = new boolean[totalCols];

            // Step 1: Extend previous heights
            for (int[] pair : previousRowHeights) {
                int previousHeight = pair[0];
                int columnIndex = pair[1];

                if (matrix[row][columnIndex] == 1) {
                    currentRowHeights.add(new int[]{previousHeight + 1, columnIndex});
                    columnVisited[columnIndex] = true;
                }
            }

            // Step 2: Add new columns with height = 1
            for (int col = 0; col < totalCols; col++) {
                if (!columnVisited[col] && matrix[row][col] == 1) {
                    currentRowHeights.add(new int[]{1, col});
                }
            }

            // Step 3: Compute max area
            for (int i = 0; i < currentRowHeights.size(); i++) {
                int width = i + 1;
                int height = currentRowHeights.get(i)[0];

                maximumArea = Math.max(maximumArea, width * height);
            }

            // Step 4: Move to next row
            previousRowHeights = currentRowHeights;
        }

        return maximumArea;
    }
}
