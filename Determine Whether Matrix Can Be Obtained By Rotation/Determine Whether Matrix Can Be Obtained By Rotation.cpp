// Solution for Determine Whether Matrix Can Be Obtained By Rotation in CPP

class Solution {
public:

    /*
        Function to rotate matrix by 90° clockwise

        Step 1: Transpose the matrix
        Step 2: Reverse each row

        WHY this works:
        - Transpose converts rows → columns
        - Reversing rows completes 90° rotation
    */
    void rotate90Clockwise(vector<vector<int>>& matrix, int size) {

        /*
            STEP 1: Transpose
            Convert matrix[i][j] → matrix[j][i]

            Example:
            1 2 3       1 4 7
            4 5 6  -->  2 5 8
            7 8 9       3 6 9
        */
        for (int row = 0; row < size; row++) {
            for (int col = row; col < size; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        /*
            STEP 2: Reverse each row

            Example:
            1 4 7       7 4 1
            2 5 8  -->  8 5 2
            3 6 9       9 6 3
        */
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        int n = mat.size();

        /*
            Try all 4 possible rotations:
            0°, 90°, 180°, 270°
        */
        for (int rotation = 0; rotation < 4; rotation++) {

            bool isSame = true;

            /*
                Check if current matrix matches target
            */
            for (int row = 0; row < n && isSame; row++) {
                for (int col = 0; col < n; col++) {
                    if (mat[row][col] != target[row][col]) {
                        isSame = false;
                        break;
                    }
                }
                if (!isSame) {
                    break;
                }
            }

            /*
                If match found → return true
            */
            if (isSame) return true;

            /*
                Otherwise rotate matrix by 90° and try again
            */
            rotate90Clockwise(mat, n);
        }

        return false;
    }
};
