// Solution for Add Binary in JAVA

class Solution {
    public String addBinary(String a, String b) {

        int indexA = a.length() - 1;
        int indexB = b.length() - 1;

        StringBuilder result = new StringBuilder();
        int carry = 0;

        while (indexA >= 0 || indexB >= 0) {

            int currentSum = carry;

            if (indexA >= 0) {
                currentSum += a.charAt(indexA) - '0';
                indexA--;
            }

            if (indexB >= 0) {
                currentSum += b.charAt(indexB) - '0';
                indexB--;
            }

            result.append(currentSum % 2);
            carry = currentSum / 2;
        }

        // If carry remains
        if (carry > 0) {
            result.append('1');
        }

        // Reverse since we built from LSB → MSB
        return result.reverse().toString();
    }
}
