# Solution for Valid Sudoku in PY

class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        # Set to track if we have already seen a number in row/col/box
        seen = set()

        # Traverse each cell in the Sudoku board
        for row in range(9):
            for col in range(9):

                # Skip empty cells
                if board[row][col] == '.':
                    continue

                num = board[row][col]

                # Create unique identifiers for row, column, and box
                rowKey = f"{num}_ROW_{row}"
                colKey = f"{num}_COL_{col}"
                boxKey = f"{num}_BOX_{row // 3}_{col // 3}"

                # If number already exists in row/col/box -> invalid Sudoku
                if rowKey in seen or colKey in seen or boxKey in seen:
                    return False

                # Otherwise, insert into the set
                seen.add(rowKey)
                seen.add(colKey)
                seen.add(boxKey)

        return True  # If no duplicates found, board is valid
