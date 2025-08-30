// Solution for Valid Sudoku in CPP

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Set to track if we have already seen a number in row/col/box
        unordered_set<string> seen;

        // Traverse each cell in the Sudoku board
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                
                // Skip empty cells
                if (board[row][col] == '.') continue;

                // Represent the number as string
                string num(1, board[row][col]);

                // Create unique identifiers for row, column, and box
                string rowKey  = num + "_ROW_" + to_string(row);
                string colKey  = num + "_COL_" + to_string(col);
                string boxKey  = num + "_BOX_" + to_string(row / 3) + "_" + to_string(col / 3);

                // If number already exists in row/col/box -> invalid Sudoku
                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                    return false;
                }

                // Otherwise, insert into the set
                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }
        return true; // If no duplicates found, board is valid
    }
};
