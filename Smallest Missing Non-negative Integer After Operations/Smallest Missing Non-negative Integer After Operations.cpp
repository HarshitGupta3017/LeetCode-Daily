// Solution for Smallest Missing Non-negative Integer After Operations in CPP

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

        // Vector to store the frequency of each remainder class modulo 'value'
        vector<int> remainderFrequency(value, 0);

        // Count how many numbers fall into each remainder class (0 to value - 1)
        for (const auto& num : nums) {
            // Normalize remainder to be non-negative
            int remainder = ((num % value) + value) % value;
            remainderFrequency[remainder]++;
        }

        int currentNumber = 0;

        // Try to build each integer starting from 0
        while (true) {
            // Find which remainder class this number would need
            int remainderClass = currentNumber % value;

            // If we have any numbers left in this class, use one to build this number
            if (remainderFrequency[remainderClass] > 0) {
                remainderFrequency[remainderClass]--;
                currentNumber++;  // Move on to try the next number
            } else {
                // If we can't build this number, it's the MEX (minimum excluded)
                return currentNumber;
            }
        }

        return -1; // Unreachable, added for completeness
    }
};
