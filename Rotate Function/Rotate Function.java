// Solution for Rotate Function in JAVA

class Solution {
    public int maxRotateFunction(int[] nums) {

        int n = nums.length;

        int totalSum = 0;   // Sum of all elements
        int currentValue = 0; // F(0)

        // Step 1: Compute total sum and F(0)
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            currentValue += i * nums[i];
        }

        int maximumValue = currentValue;

        // Step 2: Use recurrence relation
        for (int rotation = 0; rotation < n; rotation++) {
            currentValue = currentValue + totalSum
                         - n * nums[n - 1 - rotation];

            maximumValue = Math.max(maximumValue, currentValue);
        }

        return maximumValue;
    }
}
