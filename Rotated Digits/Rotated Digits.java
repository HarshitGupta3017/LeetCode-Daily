// Solution for Rotated Digits in JAVA

class Solution {

    // Check if number is "good"
    private boolean isGoodNumber(int number) {

        boolean hasValidChange = false;

        while (number > 0) {
            int digit = number % 10;

            // Invalid digits
            if (digit == 3 || digit == 4 || digit == 7)
                return false;

            // Digits that change after rotation
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                hasValidChange = true;

            number /= 10;
        }

        return hasValidChange;
    }

    public int rotatedDigits(int n) {

        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (isGoodNumber(i)) count++;
        }

        return count;
    }
}
