// Solution for Delete Columns to Make Sorted III in CPP

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int numberOfRows = strs.size();          // Total number of strings
        int numberOfColumns = strs[0].size();    // Length of each string

        // dp[col] = length of longest valid column sequence ending at 'col'
        vector<int> longestSequenceEndingAt(numberOfColumns, 1);

        int longestValidSequence = 1;

        // Iterate over each column as the ending column
        for (int currentCol = 0; currentCol < numberOfColumns; currentCol++) {

            // Try extending sequences ending at previous columns
            for (int previousCol = 0; previousCol < currentCol; previousCol++) {

                bool canExtend = true;

                // Check validity across ALL rows
                for (int row = 0; row < numberOfRows; row++) {
                    // If order breaks in any row, extension is invalid
                    if (strs[row][previousCol] > strs[row][currentCol]) {
                        canExtend = false;
                        break;
                    }
                }

                // If column transition is valid, update DP
                if (canExtend) {
                    longestSequenceEndingAt[currentCol] =
                        max(longestSequenceEndingAt[currentCol],
                            longestSequenceEndingAt[previousCol] + 1);
                }
            }

            // Track overall LIS
            longestValidSequence =
                max(longestValidSequence, longestSequenceEndingAt[currentCol]);
        }

        // Minimum deletions = total columns - max columns we can keep
        return numberOfColumns - longestValidSequence;
    }
};
