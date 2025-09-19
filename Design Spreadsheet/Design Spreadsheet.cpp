// Solution for Design Spreadsheet in CPP

class Spreadsheet {
public:
    // Grid: rows × 26 columns ('A' to 'Z')
    vector<vector<int>> grid;

    // Constructor: initialize all cells with 0
    Spreadsheet(int rows) {
        grid.assign(rows, vector<int>(26, 0));
    }

    // Helper: parse cell reference like "B12" → (row, col)
    pair<int, int> parseCell(const string& cell) {
        int col = cell[0] - 'A';            // Convert column letter to index
        int row = stoi(cell.substr(1)) - 1; // Convert row number (1-indexed) to 0-indexed
        return {row, col};
    }

    // Set value of a specific cell
    void setCell(string cell, int value) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = value;
    }

    // Reset specific cell back to 0
    void resetCell(string cell) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = 0;
    }

    // Helper: evaluate either a number or a cell reference
    int evaluate(string& token) {
        if (isdigit(token[0])) {
            return stoi(token); // Direct number
        }
        auto [row, col] = parseCell(token);
        return grid[row][col]; // Look up from spreadsheet
    }

    // Evaluate formula of the form "=X+Y"
    int getValue(string formula) {
        string expr = formula.substr(1);       // Remove leading '='
        int plusPos = expr.find('+');          // Find '+'
        
        string left = expr.substr(0, plusPos); // Left operand
        string right = expr.substr(plusPos + 1); // Right operand
        
        return evaluate(left) + evaluate(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
