// Solution for Determine Whether Matrix Can Be Obtained By Rotation in JAVA

class Solution {

    /*
        Function to rotate matrix by 90° clockwise
        Step 1: Transpose
        Step 2: Reverse each row
    */
    public void rotate90Clockwise(int[][] matrix, int size) {

        // STEP 1: Transpose
        for (int row = 0; row < size; row++) {
            for (int col = row; col < size; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }

        // STEP 2: Reverse each row
        for (int row = 0; row < size; row++) {
            int left = 0, right = size - 1;
            while (left < right) {
                int temp = matrix[row][left];
                matrix[row][left] = matrix[row][right];
                matrix[row][right] = temp;
                left++;
                right--;
            }
        }
    }

    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;

        // Try all 4 rotations
        for (int rotation = 0; rotation < 4; rotation++) {

            boolean isSame = true;

            // Check if matrices match
            for (int row = 0; row < n && isSame; row++) {
                for (int col = 0; col < n; col++) {
                    if (mat[row][col] != target[row][col]) {
                        isSame = false;
                        break;
                    }
                }
            }

            if (isSame) return true;

            // Rotate and try again
            rotate90Clockwise(mat, n);
        }

        return false;
    }
}
