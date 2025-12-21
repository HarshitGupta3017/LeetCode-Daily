// Solution for Delete Columns to Make Sorted II in CPP

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int numberOfStrings = strs.size();        // Total rows
        int stringLength = strs[0].size();        // Total columns
        int deletedColumns = 0;                   // Answer

        // Tracks whether strs[i] < strs[i+1] is already guaranteed
        vector<bool> isPairConfirmedSorted(numberOfStrings - 1, false);

        // Iterate column by column
        for (int col = 0; col < stringLength; col++) {

            bool shouldDeleteColumn = false;

            // Step 1: Check if this column breaks lexicographic order
            for (int row = 0; row < numberOfStrings - 1; row++) {

                // Only check pairs that are NOT yet confirmed sorted
                if (!isPairConfirmedSorted[row] &&
                    strs[row][col] > strs[row + 1][col]) {

                    // Order violated → must delete this column
                    shouldDeleteColumn = true;
                    deletedColumns++;
                    break;
                }
            }

            // If column is deleted, move to next column
            if (shouldDeleteColumn) continue;

            // Step 2: Lock ordering for pairs resolved by this column
            for (int row = 0; row < numberOfStrings - 1; row++) {

                if (!isPairConfirmedSorted[row] &&
                    strs[row][col] < strs[row + 1][col]) {

                    // This pair is permanently sorted
                    isPairConfirmedSorted[row] = true;
                }
            }
        }

        return deletedColumns;
    }
};
