// Solution for Smallest Missing Non-negative Integer After Operations in JAVA

class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        // Array to store the frequency of each remainder class modulo 'value'
        int[] remainderFrequency = new int[value];

        // Count how many numbers fall into each remainder class (0 to value - 1)
        for (int num : nums) {
            int remainder = ((num % value) + value) % value;
            remainderFrequency[remainder]++;
        }

        int currentNumber = 0;

        // Try to build each integer starting from 0
        while (true) {
            int remainderClass = currentNumber % value;

            // If we have any numbers left in this class, use one to build this number
            if (remainderFrequency[remainderClass] > 0) {
                remainderFrequency[remainderClass]--;
                currentNumber++;
            } else {
                // If we can't build this number, it's the MEX (minimum excluded)
                return currentNumber;
            }
        }
    }
}
