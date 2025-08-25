// Solution for Diagonal Traverse in CPP

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Map to group elements by the sum of their indices (i + j)
        map<int, vector<int>> diagonalMap;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int diagonalKey = row + col;
                diagonalMap[diagonalKey].push_back(mat[row][col]);
            }
        }

        vector<int> result;
        bool reverseFlag = true; // Used to alternate reversing of diagonals

        // Process diagonals in order of their keys (0, 1, 2, ...)
        for (auto& entry : diagonalMap) {
            vector<int>& diagonal = entry.second;

            // Reverse every alternate diagonal
            if (reverseFlag) {
                reverse(diagonal.begin(), diagonal.end());
            }

            // Append diagonal elements to result
            for (int num : diagonal) {
                result.push_back(num);
            }

            // Alternate the reverse flag for the next diagonal
            reverseFlag = !reverseFlag;
        }

        return result;
    }
};
