// Solution for Minimum Operations to Make a Uni-Value Grid in JAVA

class Solution {
    public int minOperations(int[][] grid, int x) {

        List<Integer> flattenedValues = new ArrayList<>();

        // Step 1: Flatten the 2D grid into a 1D list
        for (int[] row : grid) {
            for (int value : row) {
                flattenedValues.add(value);
            }
        }

        // Step 2: Sort values to easily pick median
        Collections.sort(flattenedValues);

        int totalElements = flattenedValues.size();

        // Step 3: Check modular consistency
        int requiredRemainder = flattenedValues.get(0) % x;

        // Median minimizes total absolute difference
        int targetValue = flattenedValues.get(totalElements / 2);

        int totalOperations = 0;

        // Step 4: Calculate total operations
        for (int value : flattenedValues) {

            // If remainder differs → impossible to equalize
            if (value % x != requiredRemainder) {
                return -1;
            }

            // Number of operations needed to convert value → targetValue
            totalOperations += Math.abs(value - targetValue) / x;
        }

        return totalOperations;
    }
}
