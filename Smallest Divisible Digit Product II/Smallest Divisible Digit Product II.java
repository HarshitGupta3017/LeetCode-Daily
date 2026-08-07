// Solution for Smallest Divisible Digit Product II in JAVA

class Solution {

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    // Greedily builds the lexicographically smallest suffix
    // that satisfies the remaining required factor.
    private String buildSuffix(long required, int slots) {
        StringBuilder suffix = new StringBuilder();

        for (int digit = 9; digit >= 2; digit--) {
            while (required % digit == 0) {
                suffix.append((char) ('0' + digit));
                required /= digit;
            }
        }

        if (required != 1) {
            suffix.append('X'); // sentinel
        }

        while (suffix.length() < slots) {
            suffix.append('1');
        }

        return suffix.reverse().toString();
    }

    public String smallestNumber(String num, long t) {
        int n = num.length();

        long remaining = t;
        int[] primes = {2, 3, 5, 7};

        for (int p : primes) {
            while (remaining % p == 0) {
                remaining /= p;
            }
        }

        if (remaining != 1) return "-1";

        long[] remainingFactor = new long[n + 1];
        remainingFactor[0] = t;

        for (int i = 0; i < n; i++) {
            int digit = num.charAt(i) - '0';

            if (digit == 0) break;

            remainingFactor[i + 1] =
                    remainingFactor[i] / gcd(remainingFactor[i], digit);
        }

        if (remainingFactor[n] == 1) return num;

        int firstZero = num.indexOf('0');
        int searchUpTo = (firstZero != -1) ? firstZero : n - 1;

        for (int i = searchUpTo; i >= 0; i--) {
            long neededFactor = remainingFactor[i];
            int freeSlots = n - 1 - i;

            for (int digit = (num.charAt(i) - '0') + 1; digit <= 9; digit++) {
                long factorAfterDigit =
                        neededFactor / gcd(neededFactor, digit);

                String suffix = buildSuffix(factorAfterDigit, freeSlots);

                if (suffix.length() == freeSlots) {
                    return num.substring(0, i)
                            + (char) ('0' + digit)
                            + suffix;
                }
            }
        }

        return buildSuffix(t, n + 1);
    }
}
