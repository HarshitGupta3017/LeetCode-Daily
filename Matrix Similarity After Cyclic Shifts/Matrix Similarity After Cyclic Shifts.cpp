// Solution for Matrix Similarity After Cyclic Shifts in CPP

class Solution {
public:
    bool areSimilar(vector<vector<int>>& matrix, int k) {
        int totalRows = matrix.size();        // Number of rows (m)
        int totalCols = matrix[0].size();     // Number of columns (n)

        // Shifting by n (or multiples of n) results in the same row
        k = k % totalCols;

        // If no effective shift, matrix remains unchanged
        if (k == 0) return true;

        // Traverse each row
        for (int row = 0; row < totalRows; row++) {

            // Traverse each column in the current row
            for (int col = 0; col < totalCols; col++) {

                int shiftedIndex;

                // For odd-indexed rows → shift RIGHT
                if (row % 2 == 1) {
                    // Right shift: element comes from (col - k)
                    shiftedIndex = (col - k + totalCols) % totalCols;
                } 
                // For even-indexed rows → shift LEFT
                else {
                    // Left shift: element comes from (col + k)
                    shiftedIndex = (col + k) % totalCols;
                }

                // Compare current element with the element at its shifted position
                // If any mismatch is found, matrix is not identical after k steps
                if (matrix[row][col] != matrix[row][shiftedIndex]) {
                    return false;
                }
            }
        }

        // If all elements match their shifted positions, matrix remains unchanged
        return true;
    }
};
