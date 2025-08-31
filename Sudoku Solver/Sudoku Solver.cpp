// Solution for Sudoku Solver in CPP

class Solution {
public:

    // Function to check if placing 'digit' at (row, col) is valid
    bool isValidPlacement(vector<vector<char>>& board, int row, int col, char digit) {
        // Check the current row and column
        for (int k = 0; k < 9; k++) {
            if (board[row][k] == digit) return false;  // Same digit already exists in the row
            if (board[k][col] == digit) return false;  // Same digit already exists in the column
        }

        // Check the corresponding 3x3 sub-box
        int startRow = (row / 3) * 3;  
        int startCol = (col / 3) * 3;  
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == digit) {
                    return false;  // Same digit exists in the 3x3 box
                }
            }
        }
        return true;  // Placement is valid
    }

    // Recursive function to solve Sudoku using backtracking
    bool solveSudokuHelper(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // If the current cell is empty, try filling it
                if (board[row][col] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        // Check if placing 'digit' is valid
                        if (isValidPlacement(board, row, col, digit)) {
                            board[row][col] = digit;  // Place the digit

                            // Recur to solve the rest of the board
                            if (solveSudokuHelper(board)) {
                                return true;  // If solved, return true
                            }

                            // Backtrack: Undo the placement
                            board[row][col] = '.';
                        }
                    }
                    // If no digit can be placed, return false (dead end)
                    return false;
                }
            }
        }
        return true;  // If no empty cells left, board is solved
    }

    // Main function to solve Sudoku
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};
