// Solution for Sort Matrix by Diagonals in CPP

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Maps to store diagonals for bottom-left and top-right triangles
        // Diagonals are identified by (i - j), which is unique for each diagonal
        map<int, vector<int>> bottomLeftDiagonals;
        map<int, vector<int>> topRightDiagonals;

        // Step 1: Group elements into diagonals based on their (i - j) value
        // Elements on the same diagonal will have the same (i - j) value
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row >= col) {
                    // For diagonals in the bottom-left triangle (i >= j)
                    // Add element to the corresponding diagonal in the bottom-left map
                    bottomLeftDiagonals[row - col].push_back(grid[row][col]);
                } else {
                    // For diagonals in the top-right triangle (i < j)
                    // Add element to the corresponding diagonal in the top-right map
                    topRightDiagonals[row - col].push_back(grid[row][col]);
                }
            }
        }

        // Step 2: Sort the diagonals
        // - Diagonals in the bottom-left triangle need to be sorted in increasing order
        // - Diagonals in the top-right triangle need to be sorted in decreasing order

        // Sort diagonals for bottom-left triangle (increasing order)
        for (auto& diagonal : bottomLeftDiagonals) {
            sort(diagonal.second.begin(), diagonal.second.end());
        }

        // Sort diagonals for top-right triangle (decreasing order)
        for (auto& diagonal : topRightDiagonals) {
            sort(diagonal.second.begin(), diagonal.second.end(), greater<int>());
        }

        // Step 3: Rebuild the matrix with sorted diagonal elements
        // - Pop elements from the sorted diagonals and assign them back to the matrix
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row >= col) {
                    // Pop the largest element from the bottom-left diagonal and assign to grid
                    grid[row][col] = bottomLeftDiagonals[row - col].back();
                    bottomLeftDiagonals[row - col].pop_back();
                } else {
                    // Pop the smallest element from the top-right diagonal and assign to grid
                    grid[row][col] = topRightDiagonals[row - col].back();
                    topRightDiagonals[row - col].pop_back();
                }
            }
        }

        // Return the modified matrix
        return grid;
    }
};
