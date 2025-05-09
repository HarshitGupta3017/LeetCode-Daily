// Solution for Count Number of Balanced Permutations in JAVA

class Solution {
    int n, totalDigitSum;
    int MOD = (int)1e9 + 7;
    long totalPermPossible = 0;

    // Fast power function using binary exponentiation
    long findPower(long a, long b) {
        if (b == 0) return 1;
        long half = findPower(a, b / 2);
        long res = (half * half) % MOD;
        if (b % 2 == 1) res = (res * a) % MOD;
        return res;
    }

    int solve(int digit, int evenIdxDigitsCount, int currSum,
              int[] freq, long[] fermatFact, Integer[][][] t) {
        if (digit == 10) {
            return (currSum == totalDigitSum / 2 && evenIdxDigitsCount == (n + 1) / 2) ? (int)totalPermPossible : 0;
        }
        if (t[digit][evenIdxDigitsCount][currSum] != null) {
            return t[digit][evenIdxDigitsCount][currSum];
        }
        long ways = 0;
        for (int count = 0; count <= Math.min(freq[digit], (n + 1) / 2 - evenIdxDigitsCount); count++) {
            int evenPosCount = count;
            int oddPosCount = freq[digit] - count;
            long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount]) % MOD;
            long val = solve(digit + 1, evenIdxDigitsCount + evenPosCount,
                             currSum + digit * count, freq, fermatFact, t);
            ways = (ways + (val * div) % MOD) % MOD;
        }
        return t[digit][evenIdxDigitsCount][currSum] = (int)ways;
    }

    public int countBalancedPermutations(String num) {
        n = num.length();
        totalDigitSum = 0;
        int[] freq = new int[10];

        for (int i = 0; i < n; i++) {
            int digit = num.charAt(i) - '0';
            totalDigitSum += digit;
            freq[digit]++;
        }

        if (totalDigitSum % 2 == 1) return 0;

        // Precompute factorials and their modular inverses
        long[] fact = new long[n + 1];
        fact[0] = fact[1] = 1;
        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        long[] fermatFact = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(fact[i], MOD - 2);
        }

        totalPermPossible = (fact[(n + 1) / 2] * fact[n / 2]) % MOD;

        Integer[][][] t = new Integer[10][(n + 1) / 2 + 1][totalDigitSum + 1];
        return solve(0, 0, 0, freq, fermatFact, t);
    }
}
