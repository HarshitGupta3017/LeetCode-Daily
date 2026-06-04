// Solution for Total Waviness of Numbers in Range I in CPP

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int totalWavinessCount = 0;

        // Check every number in the inclusive range [num1, num2].
        for (int currentNumber = num1; currentNumber <= num2; currentNumber++) {

            // Numbers with fewer than 3 digits cannot have peaks or valleys.
            if (currentNumber < 100)
                continue;

            // Store digits in reverse order:
            // Example: 58371 -> {1, 7, 3, 8, 5}
            vector<int> digits;
            int tempNumber = currentNumber;

            while (tempNumber > 0) {
                digits.push_back(tempNumber % 10);
                tempNumber /= 10;
            }

            /*
                Since digits are stored in reverse order, the neighbor
                relationship is also reversed. However, peaks and valleys
                are still detected correctly because we only compare a digit
                with its immediate left and right neighbors in this reversed
                representation.

                Example:
                    Original number : 58371
                    Reversed digits : {1, 7, 3, 8, 5}

                Digit '3' is between '7' and '8' in both representations,
                so the peak/valley property remains unchanged.
            */
            for (int digitIndex = 1; digitIndex < digits.size() - 1; digitIndex++) {
                int leftNeighbor  = digits[digitIndex - 1];
                int currentDigit  = digits[digitIndex];
                int rightNeighbor = digits[digitIndex + 1];

                bool isPeak = currentDigit > leftNeighbor && currentDigit > rightNeighbor;

                bool isValley = currentDigit < leftNeighbor && currentDigit < rightNeighbor;

                if (isPeak || isValley)
                    totalWavinessCount++;
            }
        }

        return totalWavinessCount;
    }
};
