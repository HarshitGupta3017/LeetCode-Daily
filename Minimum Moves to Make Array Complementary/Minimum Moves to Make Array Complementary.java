// Solution for Minimum Moves to Make Array Complementary in JAVA

class Solution {
    public int minMoves(int[] nums, int limit) {

        int totalElements = nums.length;

        // Difference array to track move cost changes
        int[] differenceArray = new int[2 * limit + 2];

        // Process each complementary pair
        for (int index = 0; index < totalElements / 2; index++) {

            int leftValue = nums[index];
            int rightValue = nums[totalElements - index - 1];

            int currentSum = leftValue + rightValue;

            // Minimum sum achievable with one move
            int minimumOneMoveSum = Math.min(leftValue, rightValue) + 1;

            // Maximum sum achievable with one move
            int maximumOneMoveSum = Math.max(leftValue, rightValue) + limit;

            // Default cost = 2 moves
            differenceArray[2] += 2;
            differenceArray[2 * limit + 1] -= 2;

            // Cost reduces to 1 move
            differenceArray[minimumOneMoveSum] -= 1;
            differenceArray[maximumOneMoveSum + 1] += 1;

            // Cost reduces to 0 moves
            differenceArray[currentSum] -= 1;
            differenceArray[currentSum + 1] += 1;
        }

        int minimumMoves = Integer.MAX_VALUE;

        // Build prefix sum
        for (int targetSum = 2; targetSum <= 2 * limit; targetSum++) {

            differenceArray[targetSum] += differenceArray[targetSum - 1];

            minimumMoves = Math.min(minimumMoves, differenceArray[targetSum]);
        }

        return minimumMoves;
    }
}
