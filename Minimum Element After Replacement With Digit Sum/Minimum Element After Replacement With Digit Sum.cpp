// Solution for Minimum Element After Replacement With Digit Sum in CPP

class Solution {
public:
    int minElement(vector<int>& nums) {

        // Maximum possible digit sum:
        // 9999 -> 9 + 9 + 9 + 9 = 36
        int minimumValue = 37;

        for (int number : nums) {

            int digitSum = 0;

            // Calculate sum of digits
            // for current number
            while (number > 0) {

                digitSum += number % 10;

                number /= 10;
            }

            // Maintain minimum digit sum
            // among all transformed values
            minimumValue = min(minimumValue, digitSum);
        }

        return minimumValue;
    }
};
