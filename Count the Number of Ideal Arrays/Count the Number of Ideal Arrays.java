// Solution for Count the Number of Ideal Arrays in JAVA

class Solution {
    int M = (int)1e9 + 7;
    int[][] dp;
    int[] count;

    public void findSets(int m) {
        if (dp[m][1] != 0) return;
        dp[m][1] = 1;
        count[1]++;
        for (int div = 2; div <= m; div++) {
            if (m % div == 0) {
                findSets(m / div);
                for (int len = 1; len < 15; len++) {
                    if (dp[m / div][len] != 0) {
                        dp[m][len + 1] += dp[m / div][len];
                        count[len + 1] += dp[m / div][len];
                    }
                }
            }
        }
    }

    public long findPower(long a, long b) {
        if (b == 0) return 1;
        long half = findPower(a, b / 2);
        long result = (half * half) % M;
        if (b % 2 == 1) result = (result * a) % M;
        return result;
    }

    public long modularnCr(int n, int r, long[] fact) {
        if (r < 0 || r > n) return 0;
        long a = fact[n];
        long b = (fact[r] * fact[n - r]) % M;
        return (a * findPower(b, M - 2)) % M;
    }

    public int idealArrays(int n, int maxValue) {
        dp = new int[maxValue + 1][15];
        count = new int[15];

        for (int val = 1; val <= maxValue; val++) {
            findSets(val);
        }

        long[] fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % M;
        }

        long result = 0;
        for (int len = 1; len < 15; len++) {
            if (n < len) break;
            if (count[len] != 0) {
                long possibilities = modularnCr(n - 1, len - 1, fact);
                result = (result + (count[len] * possibilities) % M) % M;
            }
        }
        return (int)result;
    }
}
