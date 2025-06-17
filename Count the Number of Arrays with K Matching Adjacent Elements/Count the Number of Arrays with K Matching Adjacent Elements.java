// Solution for Count the Number of Arrays with K Matching Adjacent Elements in JAVA

class Solution {
    final int MOD = 1_000_000_007;

    int modPow(long base, long exp) {
        long result = 1;
        base %= MOD;
        while (exp > 0) {
            if ((exp & 1) == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return (int) result;
    }

    public int countGoodArrays(int n, int m, int k) {
        int[] fact = new int[n + 1];
        int[] invFact = new int[n + 1];
        fact[0] = invFact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (int)((1L * fact[i - 1] * i) % MOD);
        }
        for (int i = 0; i <= n; i++) {
            invFact[i] = modPow(fact[i], MOD - 2);
        }

        int equalPairsWays = (int)((1L * fact[n - 1] * invFact[k] % MOD * invFact[n - k - 1]) % MOD);
        long assignWays = (1L * m * modPow(m - 1, n - k - 1)) % MOD;
        return (int)((1L * equalPairsWays * assignWays) % MOD);
    }
}
