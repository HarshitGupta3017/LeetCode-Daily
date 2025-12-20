// Solution for Delete Columns to Make Sorted in JAVA

class Solution {
    public int minDeletionSize(String[] strs) {
        int numRows = strs.length;
        int numCols = strs[0].length();
        int columnsToDelete = 0;

        // Iterate over each column
        for (int col = 0; col < numCols; col++) {
            // Check if this column is sorted
            for (int row = 1; row < numRows; row++) {
                if (strs[row].charAt(col) < strs[row - 1].charAt(col)) {
                    columnsToDelete++; // column is unsorted
                    break;
                }
            }
        }

        return columnsToDelete;
    }
}
