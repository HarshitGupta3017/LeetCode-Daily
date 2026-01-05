// Solution for Maximum Matrix Sum in CPP

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        // This will store the total sum of absolute values of all elements
        long long totalAbsoluteSum = 0;

        // This will track the smallest absolute value in the matrix
        int minimumAbsoluteValue = INT_MAX;

        // Count how many negative numbers are present
        int negativeCount = 0;

        int matrixSize = matrix.size();

        // Traverse the entire matrix
        for (int row = 0; row < matrixSize; row++) {
            for (int col = 0; col < matrixSize; col++) {

                int currentValue = matrix[row][col];

                // Add absolute value to the total sum
                totalAbsoluteSum += abs(currentValue);

                // Count negative numbers
                if (currentValue < 0) {
                    negativeCount++;
                }

                // Track the smallest absolute value
                minimumAbsoluteValue = min(minimumAbsoluteValue, abs(currentValue));
            }
        }

        /*
            If the number of negative elements is even:
            → We can flip signs optimally to make all values positive
            → Maximum sum is the total absolute sum

            If the number of negative elements is odd:
            → One element must remain negative
            → To minimize loss, subtract 2 * smallest absolute value
        */
        if (negativeCount % 2 == 0) {
            return totalAbsoluteSum;
        }

        return totalAbsoluteSum - 2LL * minimumAbsoluteValue;
    }
};
