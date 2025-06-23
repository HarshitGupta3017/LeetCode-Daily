// Solution for Sum of k-Mirror Numbers in JAVA

class Solution {

    // Convert a number to its base-k representation (in reverse order)
    private String convertToBaseK(long num, int k) {
        if (num == 0) return "0";
        StringBuilder baseK = new StringBuilder();
        while (num > 0) {
            baseK.append(num % k);
            num /= k;
        }
        return baseK.toString();
    }

    // Check if a given string is a palindrome
    private boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            if (s.charAt(left++) != s.charAt(right--)) return false;
        }
        return true;
    }

    public long kMirror(int k, int n) {
        long sum = 0;
        int length = 1;

        while (n > 0) {
            int halfLength = (length + 1) / 2;

            long min = (long) Math.pow(10, halfLength - 1);
            long max = (long) Math.pow(10, halfLength) - 1;

            for (long num = min; num <= max; num++) {
                String left = Long.toString(num);
                String right = new StringBuilder(left).reverse().toString();

                String palStr = (length % 2 == 0) ? (left + right) : (left + right.substring(1));
                long palNum = Long.parseLong(palStr);

                String baseK = convertToBaseK(palNum, k);
                if (isPalindrome(baseK)) {
                    sum += palNum;
                    n--;
                    if (n == 0) break;
                }
            }
            length++;
        }

        return sum;
    }
}
