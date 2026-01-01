// Solution for Plus One in CPP

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // We start by assuming we need to add 1 to the number
        int carry = 1;

        int totalDigits = digits.size();

        // Traverse from the least significant digit (rightmost)
        for (int index = totalDigits - 1; index >= 0; index--) {

            // Add carry to the current digit
            int currentSum = digits[index] + carry;

            // Store the last digit of the sum at current position
            digits[index] = currentSum % 10;

            // Update carry (will be 1 only if currentSum was 10)
            carry = currentSum / 10;
        }

        // If carry is still left after processing all digits,
        // it means we had an overflow (e.g., 999 -> 1000)
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
