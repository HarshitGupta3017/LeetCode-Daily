// Solution for Plus One in JAVA

class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        int n = digits.length;

        // Traverse from the least significant digit
        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        // If no carry remains, return modified array
        if (carry == 0) {
            return digits;
        }

        // If carry remains (e.g., 999 → 1000), create new array
        int[] result = new int[n + 1];
        result[0] = 1;  // carry
        return result;
    }
}
