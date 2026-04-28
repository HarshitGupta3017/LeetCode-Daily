// Solution for Minimum Operations to Make a Uni-Value Grid in CPP

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> flattenedValues;

        // Step 1: Flatten the 2D grid into a 1D array
        for (const auto& row : grid) {
            for (int value : row) {
                flattenedValues.push_back(value);
            }
        }

        // Step 2: Sort values to easily pick median
        sort(flattenedValues.begin(), flattenedValues.end());

        int totalElements = flattenedValues.size();

        // Step 3: Check modular consistency (all values must have same remainder mod x)
        int requiredRemainder = flattenedValues[0] % x;

        // Median minimizes total absolute difference
        int targetValue = flattenedValues[totalElements / 2];

        int totalOperations = 0;

        // Step 4: Calculate total operations
        for (int value : flattenedValues) {

            // If remainder differs → impossible to equalize
            if (value % x != requiredRemainder) {
                return -1;
            }

            // Number of operations needed to convert value → targetValue
            totalOperations += abs(value - targetValue) / x;
        }

        return totalOperations;
    }
};
