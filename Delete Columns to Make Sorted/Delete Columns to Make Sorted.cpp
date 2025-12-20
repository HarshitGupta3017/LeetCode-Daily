// Solution for Delete Columns to Make Sorted in CPP

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int numRows = strs.size();
        int numCols = strs[0].size();
        int columnsToDelete = 0;

        // Iterate over each column
        for (int col = 0; col < numCols; col++) {
            // Check if this column is sorted
            for (int row = 1; row < numRows; row++) {
                // If current character is smaller than the one above → column unsorted
                if (strs[row][col] < strs[row - 1][col]) {
                    columnsToDelete++; // mark for deletion
                    break; // no need to check further rows in this column
                }
            }
        }

        return columnsToDelete;
    }
};
