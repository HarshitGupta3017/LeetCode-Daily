// Solution for Next Greater Numerically Balanced Number in CPP

class Solution {
public:
    // Step 1️⃣: Map to track remaining allowed occurrences for digits 0-9
    vector<int> remainingCount = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    /**
     * @brief Recursive backtracking to build numerically balanced numbers
     * 
     * @param n        Minimum number threshold
     * @param current  Current number being constructed
     * @param digitsLeft  Number of digits left to fill
     * @return int     Smallest numerically balanced number > n, or 0 if impossible
     */
    int backtrack(int n, int current, int digitsLeft) {
        // Base case: no digits left to fill
        if (digitsLeft == 0) {
            // Verify all digits used satisfy the numerical balance property
            for (int digit = 1; digit <= 9; digit++) {
                if (remainingCount[digit] != 0 && remainingCount[digit] != digit) {
                    return 0; // Invalid number
                }
            }
            return current > n ? current : 0; // Return if valid and greater than n
        }

        int result = 0;

        // Try each digit from 1 to 9 for the next position
        for (int digit = 1; digit <= 9; digit++) {
            if (remainingCount[digit] > 0 && remainingCount[digit] <= digitsLeft) {
                remainingCount[digit]--; // Use one occurrence of this digit
                result = backtrack(n, current * 10 + digit, digitsLeft - 1);
                remainingCount[digit]++; // Backtrack: restore count

                if (result != 0) break; // Found a valid number, stop further search
            }
        }

        return result; // Return the found number or 0 if none
    }

    /**
     * @brief Finds the smallest numerically balanced number strictly greater than n
     * 
     * @param n Input number
     * @return int Smallest numerically balanced number > n
     */
    int nextBeautifulNumber(int n) {
        int numLength = to_string(n).length(); // Current number of digits

        // Step 1️⃣: Try finding a balanced number with same number of digits
        int result = backtrack(n, 0, numLength);

        // Step 2️⃣: If not found, try with one more digit
        if (result == 0) {
            result = backtrack(n, 0, numLength + 1);
        }

        return result;
    }
};
