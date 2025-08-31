# Solution for Sudoku Solver in PY

class Solution:

    # Function to check if placing 'digit' at (row, col) is valid
    def isValidPlacement(self, board, row, col, digit):
        # Check row and column
        for k in range(9):
            if board[row][k] == digit:
                return False
            if board[k][col] == digit:
                return False

        # Check 3x3 sub-box
        startRow, startCol = (row // 3) * 3, (col // 3) * 3
        for i in range(3):
            for j in range(3):
                if board[startRow + i][startCol + j] == digit:
                    return False
        return True

    # Recursive backtracking function
    def solveSudokuHelper(self, board):
        for row in range(9):
            for col in range(9):
                if board[row][col] == '.':
                    for digit in map(str, range(1, 10)):
                        if self.isValidPlacement(board, row, col, digit):
                            board[row][col] = digit  # Place digit

                            if self.solveSudokuHelper(board):
                                return True

                            # Backtrack
                            board[row][col] = '.'
                    return False  # Dead end
        return True  # Fully solved

    # Main function
    def solveSudoku(self, board):
        self.solveSudokuHelper(board)
