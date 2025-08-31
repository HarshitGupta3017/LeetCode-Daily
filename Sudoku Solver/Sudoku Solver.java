// Solution for Sudoku Solver in JAVA

class Solution {

    // Function to check if placing 'digit' at (row, col) is valid
    private boolean isValidPlacement(char[][] board, int row, int col, char digit) {
        // Check row and column
        for (int k = 0; k < 9; k++) {
            if (board[row][k] == digit) return false; // Same digit exists in row
            if (board[k][col] == digit) return false; // Same digit exists in column
        }

        // Check 3x3 sub-box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }

    // Recursive backtracking function
    private boolean solveSudokuHelper(char[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isValidPlacement(board, row, col, digit)) {
                            board[row][col] = digit; // Place digit

                            if (solveSudokuHelper(board)) {
                                return true; // Solved
                            }

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }
                    return false; // Dead end
                }
            }
        }
        return true; // Solved fully
    }

    // Main function
    public void solveSudoku(char[][] board) {
        solveSudokuHelper(board);
    }
}
