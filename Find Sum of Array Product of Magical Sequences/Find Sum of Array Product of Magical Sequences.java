// Solution for Find Sum of Array Product of Magical Sequences in JAVA

class Solution {
    static final int MOD = 1_000_000_007;
    long[] fact, invFact;

    // Fast modular exponentiation (a^b % MOD)
    long modPow(long a, long b) {
        long result = 1;
        while (b > 0) {
            if ((b & 1) == 1) result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    // Compute nCr % MOD using precomputed factorials
    long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    // Recursive DP with memoization
    long dfs(long binarySum, int idx, int remaining, int targetBits,
             int[] nums, int n, Map<String, Long> memo) {

        // Base case
        if (remaining == 0 && Long.bitCount(binarySum) == targetBits) return 1;
        if (remaining == 0 || idx >= n) return 0;

        String key = binarySum + "," + idx + "," + remaining + "," + targetBits;
        if (memo.containsKey(key)) return memo.get(key);

        long total = 0;

        // Skip current index
        total += dfs(binarySum >> 1, idx + 1, remaining, targetBits - (int)(binarySum & 1), nums, n, memo);
        total %= MOD;

        // Choose current index with frequency 1..remaining
        for (int freq = 1; freq <= remaining; freq++) {
            long newSum = binarySum + freq;

            long partial = dfs(newSum >> 1, idx + 1, remaining - freq,
                               targetBits - (int)(newSum & 1), nums, n, memo) % MOD;

            partial = (partial * modPow(nums[idx], freq)) % MOD;
            partial = (partial * nCr(remaining, freq)) % MOD;
            total = (total + partial) % MOD;
        }

        memo.put(key, total);
        return total;
    }

    public int magicalSum(int m, int k, int[] nums) {
        int n = nums.length;

        // Precompute factorials and inverses
        fact = new long[m + 1];
        invFact = new long[m + 1];
        fact[0] = 1;

        for (int i = 1; i <= m; i++) fact[i] = (fact[i - 1] * i) % MOD;
        for (int i = 0; i <= m; i++) invFact[i] = modPow(fact[i], MOD - 2);

        return (int)(dfs(0, 0, m, k, nums, n, new HashMap<>()) % MOD);
    }
}
