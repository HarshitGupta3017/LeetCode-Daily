// Solution for Delete Columns to Make Sorted III in JAVA

class Solution {
    public int minDeletionSize(String[] strs) {

        int numberOfRows = strs.length;         // Total number of strings
        int numberOfColumns = strs[0].length(); // Length of each string

        // dp[col] = length of the longest valid column sequence ending at 'col'
        int[] longestSequenceEndingAt = new int[numberOfColumns];

        // Every column can form a sequence of length 1 by itself
        for (int i = 0; i < numberOfColumns; i++) {
            longestSequenceEndingAt[i] = 1;
        }

        int longestValidSequence = 1;

        // Iterate over each column as the ending column
        for (int currentCol = 0; currentCol < numberOfColumns; currentCol++) {

            // Try extending sequences ending at previous columns
            for (int previousCol = 0; previousCol < currentCol; previousCol++) {

                boolean canExtend = true;

                // Check validity across ALL rows
                for (int row = 0; row < numberOfRows; row++) {

                    // If order breaks in any row, extension is invalid
                    if (strs[row].charAt(previousCol) >
                        strs[row].charAt(currentCol)) {

                        canExtend = false;
                        break;
                    }
                }

                // If column transition is valid, update DP
                if (canExtend) {
                    longestSequenceEndingAt[currentCol] =
                        Math.max(longestSequenceEndingAt[currentCol],
                                 longestSequenceEndingAt[previousCol] + 1);
                }
            }

            // Track overall LIS
            longestValidSequence =
                Math.max(longestValidSequence,
                         longestSequenceEndingAt[currentCol]);
        }

        // Minimum deletions = total columns - max columns we can keep
        return numberOfColumns - longestValidSequence;
    }
}
