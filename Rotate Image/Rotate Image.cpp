// Solution for Rotate Image in CPP

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int dimension = matrix.size();

        // Step 1: Transpose the matrix (swap across diagonal)
        for (int row = 0; row < dimension; row++) {
            for (int col = row + 1; col < dimension; col++) {

                // Swap symmetric elements across diagonal
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // Step 2: Reverse each row to get 90° clockwise rotation
        for (auto& currentRow : matrix) {
            reverse(currentRow.begin(), currentRow.end());
        }
    }
};
