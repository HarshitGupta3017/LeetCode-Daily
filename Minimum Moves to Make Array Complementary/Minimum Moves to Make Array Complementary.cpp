// Solution for Minimum Moves to Make Array Complementary in CPP

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int totalElements = nums.size();

        // Difference array to track move cost changes
        vector<int> differenceArray(2 * limit + 2, 0);

        // Process each complementary pair
        for (int index = 0; index < totalElements / 2; index++) {

            int leftValue = nums[index];
            int rightValue = nums[totalElements - index - 1];

            int currentSum = leftValue + rightValue;

            // Minimum sum achievable with one move
            int minimumOneMoveSum = min(leftValue, rightValue) + 1;

            // Maximum sum achievable with one move
            int maximumOneMoveSum = max(leftValue, rightValue) + limit;

            // -----------------------------------
            // Default cost = 2 moves
            // for every possible target sum
            // -----------------------------------
            differenceArray[2] += 2;
            differenceArray[2 * limit + 1] -= 2;

            // -----------------------------------
            // Cost reduces to 1 move
            // for sums in:
            // [minimumOneMoveSum, maximumOneMoveSum]
            // -----------------------------------
            differenceArray[minimumOneMoveSum] -= 1;
            differenceArray[maximumOneMoveSum + 1] += 1;

            // -----------------------------------
            // Cost reduces to 0 moves
            // for exact currentSum
            // -----------------------------------
            differenceArray[currentSum] -= 1;
            differenceArray[currentSum + 1] += 1;
        }

        int minimumMoves = INT_MAX;

        // Build prefix sum to compute actual move counts
        for (int targetSum = 2; targetSum <= 2 * limit; targetSum++) {

            differenceArray[targetSum] += differenceArray[targetSum - 1];

            minimumMoves = min(minimumMoves, differenceArray[targetSum]);
        }

        return minimumMoves;
    }
};
