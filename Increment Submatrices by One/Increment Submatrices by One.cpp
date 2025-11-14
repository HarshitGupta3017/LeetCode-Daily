// Solution for Increment Submatrices by One in CPP

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        // 🔹 2D matrix used to store difference values for efficient range updates
        vector<vector<int>> diffMatrix(n, vector<int>(n, 0));

        // 🔹 Process each query using row-wise difference array technique
        for (const auto& query : queries) {
            int rowStart = query[0];
            int colStart = query[1];
            int rowEnd   = query[2];
            int colEnd   = query[3];

            // For each affected row, we add +1 at colStart
            // and -1 after colEnd to mark where the increment stops.
            for (int row = rowStart; row <= rowEnd; row++) {

                // Mark start of +1 influence
                diffMatrix[row][colStart] += 1;

                // Mark where the +1 influence ends
                if (colEnd + 1 < n)
                    diffMatrix[row][colEnd + 1] -= 1;
            }
        }

        // 🔹 Convert difference matrix into final values using prefix sum per row
        for (int row = 0; row < n; row++) {
            for (int col = 1; col < n; col++) {
                diffMatrix[row][col] += diffMatrix[row][col - 1];
            }
        }

        // diffMatrix is now the final matrix
        return diffMatrix;
    }
};
