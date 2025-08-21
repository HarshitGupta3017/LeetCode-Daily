// Solution for Count Submatrices With All Ones in CPP

class Solution {
public: 

    // Helper function to count the number of subarrays consisting of only 1's
    int countSubarraysWithOnes(vector<int>& binaryArray) {
        int consecutiveOnes = 0;   // Tracks consecutive 1's
        int totalSubarrays = 0;    // Stores total subarrays of 1's

        for (int& value : binaryArray) {
            if (value == 0) {
                consecutiveOnes = 0; // Reset count if a 0 is found
            } else {
                consecutiveOnes++;   // Extend the streak of consecutive 1's
            }
            totalSubarrays += consecutiveOnes; 
            // Add all subarrays ending at this index
        }
        return totalSubarrays;
    }

    int numSubmat(vector<vector<int>>& matrix) {
        int totalRows = matrix.size();
        int totalCols = matrix[0].size();
        int totalSubmatrices = 0;

        // Fix a starting row
        for (int startRow = 0; startRow < totalRows; startRow++) {
            
            // Create a column mask initialized with 1's
            vector<int> columnMask(totalCols, 1);

            // Expand downwards row by row
            for (int endRow = startRow; endRow < totalRows; endRow++) {
                
                // Update column mask: mark columns that have all 1's
                for (int col = 0; col < totalCols; col++) {
                    columnMask[col] = columnMask[col] & matrix[endRow][col];
                }

                // Count submatrices formed using rows [startRow...endRow]
                totalSubmatrices += countSubarraysWithOnes(columnMask);
            }
        }
        return totalSubmatrices;
    }
};
