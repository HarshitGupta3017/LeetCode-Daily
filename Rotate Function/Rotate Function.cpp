// Solution for Rotate Function in CPP

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int totalElements = nums.size();

        int totalSum = 0;   // Sum of all elements
        int currentValue = 0; // F(0)

        // Step 1: Compute total sum and F(0)
        for (int index = 0; index < totalElements; index++) {
            totalSum += nums[index];
            currentValue += index * nums[index];
        }

        int maximumValue = currentValue;

        // Step 2: Use recurrence relation to compute F(k)
        for (int rotation = 0; rotation < totalElements; rotation++) {

            // Transition:
            // F(k+1) = F(k) + totalSum - n * nums[n - 1 - k]
            currentValue = currentValue + totalSum
                           - totalElements * nums[totalElements - 1 - rotation];

            // Update maximum
            maximumValue = max(maximumValue, currentValue);
        }

        return maximumValue;
    }
};
