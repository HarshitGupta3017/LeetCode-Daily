// Solution for Maximum Matrix Sum in JAVA

class Solution {
    public long maxMatrixSum(int[][] matrix) {

        // Stores the total sum of absolute values of all elements
        long totalAbsoluteSum = 0;

        // Tracks the smallest absolute value in the matrix
        int minimumAbsoluteValue = Integer.MAX_VALUE;

        // Counts the number of negative elements
        int negativeCount = 0;

        int matrixSize = matrix.length;

        // Traverse the entire matrix
        for (int row = 0; row < matrixSize; row++) {
            for (int col = 0; col < matrixSize; col++) {

                int currentValue = matrix[row][col];

                // Add absolute value to total sum
                totalAbsoluteSum += Math.abs(currentValue);

                // Count negatives
                if (currentValue < 0) {
                    negativeCount++;
                }

                // Track minimum absolute value
                minimumAbsoluteValue =
                        Math.min(minimumAbsoluteValue, Math.abs(currentValue));
            }
        }

        /*
            If number of negative values is even:
            → All values can be made positive
            → Maximum sum = total absolute sum

            If odd:
            → One value must stay negative
            → Subtract 2 * smallest absolute value
        */
        if (negativeCount % 2 == 0) {
            return totalAbsoluteSum;
        }

        return totalAbsoluteSum - 2L * minimumAbsoluteValue;
    }
}
