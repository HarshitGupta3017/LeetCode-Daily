// Solution for Rotated Digits in CPP

class Solution {
public:

    // Check if a number is "good" after rotation
    bool isGoodNumber(int number) {

        bool hasValidChange = false; // Ensures result is different after rotation

        while (number > 0) {

            int digit = number % 10;

            // Invalid digits (cannot be rotated)
            if (digit == 3 || digit == 4 || digit == 7)
                return false;

            // Digits that change after rotation
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                hasValidChange = true;

            number /= 10;
        }

        // Must have at least one changing digit
        return hasValidChange;
    }

    int rotatedDigits(int n) {

        int goodNumbersCount = 0;

        // Check all numbers from 1 to n
        for (int currentNumber = 1; currentNumber <= n; currentNumber++) {

            if (isGoodNumber(currentNumber)) {
                goodNumbersCount++;
            }
        }

        return goodNumbersCount;
    }
};
