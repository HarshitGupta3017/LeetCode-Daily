// Solution for Valid Sudoku in JAVA

import java.util.HashSet;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Set to track if we have already seen a number in row/col/box
        HashSet<String> seen = new HashSet<>();

        // Traverse each cell in the Sudoku board
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                // Skip empty cells
                if (board[row][col] == '.') continue;

                String num = String.valueOf(board[row][col]);

                // Create unique identifiers for row, column, and box
                String rowKey = num + "_ROW_" + row;
                String colKey = num + "_COL_" + col;
                String boxKey = num + "_BOX_" + (row / 3) + "_" + (col / 3);

                // If number already exists in row/col/box -> invalid Sudoku
                if (seen.contains(rowKey) || seen.contains(colKey) || seen.contains(boxKey)) {
                    return false;
                }

                // Otherwise, insert into the set
                seen.add(rowKey);
                seen.add(colKey);
                seen.add(boxKey);
            }
        }
        return true; // If no duplicates found, board is valid
    }
}
