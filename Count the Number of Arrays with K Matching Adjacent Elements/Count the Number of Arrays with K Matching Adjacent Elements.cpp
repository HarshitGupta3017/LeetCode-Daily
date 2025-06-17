// Solution for Count the Number of Arrays with K Matching Adjacent Elements in CPP

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast exponentiation to compute (a^b) % MOD
    int modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodArrays(int n, int m, int k) {
        // Step 1: Precompute factorials and inverse factorials up to n
        vector<int> fact(n + 1, 1), invFact(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fact[i] = (1LL * fact[i - 1] * i) % MOD;
        }
        for (int i = 0; i <= n; i++) {
            invFact[i] = modPow(fact[i], MOD - 2); // Fermat's inverse mod
        }

        // Step 2: Calculate number of ways to choose k adjacent equal pairs
        // This is equivalent to choosing k positions out of (n-1)
        // (n - 1 choose k) = fact[n - 1] / (fact[k] * fact[n - k - 1])
        int equalPairsWays = ((1LL * fact[n - 1] * invFact[k]) % MOD * invFact[n - k - 1]) % MOD;

        // Step 3: For first position, choose any value from 1 to m
        // For remaining (n-k-1) non-equal positions, choose a different number (m-1 choices)
        long long assignWays = (1LL * m * modPow(m - 1, n - k - 1)) % MOD;

        // Step 4: Total good arrays = ways to place equal pairs * ways to assign values
        return (1LL * equalPairsWays * assignWays) % MOD;
    }
};
