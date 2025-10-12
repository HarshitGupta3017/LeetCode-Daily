// Solution for Find Sum of Array Product of Magical Sequences in CPP

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    // Factorials and inverse factorials for nCr computation
    vector<ll> factorial;
    vector<ll> inverseFactorial;

    /**
     * Fast modular exponentiation.
     * Computes (a^b) % MOD efficiently using binary exponentiation.
     */
    ll modPow(ll a, ll b) {
        if (b == 0) return 1;
        ll half = modPow(a, b / 2);
        ll result = (half * half) % MOD;
        if (b % 2 == 1) result = (result * a) % MOD;
        return result;
    }

    /**
     * Computes nCr % MOD using precomputed factorials and modular inverses.
     */
    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return (((factorial[n] * inverseFactorial[r]) % MOD) * inverseFactorial[n - r]) % MOD;
    }

    /**
     * Recursive DP function that computes the total magical sequence product sum.
     *
     * @param binarySum  Current accumulated binary sum of chosen indices (in base-2 form).
     * @param index      Current index in nums being considered.
     * @param remaining  Number of elements still to be chosen (m decreases each step).
     * @param targetBits Required number of set bits (k).
     * @param n          Size of nums array.
     * @param memo       DP memoization cache to store previously computed states.
     * @return           Total product sum modulo MOD.
     */
    ll computeMagicalSum(
        ll binarySum,
        int index,
        int remaining,
        int targetBits,
        vector<int>& nums,
        int n,
        map<tuple<ll, int, int, int>, ll>& memo
    ) {
        // ✅ Base case: if we've selected exactly m elements,
        // check if binarySum has exactly k set bits
        if (remaining == 0 && __builtin_popcountll(binarySum) == targetBits)
            return 1;

        // If no elements left or we've exhausted all indices
        if (remaining == 0 || index >= n)
            return 0;

        // Memoization key for this state
        auto stateKey = make_tuple(binarySum, index, remaining, targetBits);
        if (memo.count(stateKey))
            return memo[stateKey];

        ll totalProductSum = 0;

        // ⚙️ Case 1: Skip current index (move to next)
        totalProductSum = (
            totalProductSum +
            computeMagicalSum(
                binarySum >> 1,
                index + 1,
                remaining,
                targetBits - (binarySum & 1),
                nums,
                n,
                memo
            )
        ) % MOD;

        // ⚙️ Case 2: Choose current index with frequency = 1..remaining
        for (int freq = 1; freq <= remaining; freq++) {
            // Add 'freq' times this index’s contribution in binary
            ll updatedBinarySum = binarySum + freq;

            // Recursively compute sum after choosing this element 'freq' times
            ll partialResult = computeMagicalSum(
                updatedBinarySum >> 1,
                index + 1,
                remaining - freq,
                targetBits - (updatedBinarySum & 1),
                nums,
                n,
                memo
            ) % MOD;

            // Multiply result with (nums[index]^freq)
            partialResult = (partialResult * modPow(nums[index], freq)) % MOD;

            // Multiply by combination count C(remaining, freq)
            partialResult = (partialResult * nCr(remaining, freq)) % MOD;

            // Accumulate total
            totalProductSum = (totalProductSum + partialResult) % MOD;
        }

        // Store result in memo and return
        return memo[stateKey] = totalProductSum;
    }

    /**
     * Main function to compute the sum of array products for all magical sequences.
     *
     * @param m     Required sequence length.
     * @param k     Required number of set bits in binary representation.
     * @param nums  Input array representing spell powers.
     * @return      Sum of magical sequence products modulo 1e9+7.
     */
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();

        // ✅ Precompute factorials and inverse factorials for nCr
        factorial.assign(m + 1, 1);
        inverseFactorial.assign(m + 1, 1);

        for (int i = 2; i <= m; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        // Fermat's Little Theorem for modular inverse
        for (int i = 0; i <= m; i++) {
            inverseFactorial[i] = modPow(factorial[i], MOD - 2);
        }

        // DP memoization map
        map<tuple<ll, int, int, int>, ll> memo;

        // Start DFS with initial state (sum=0, index=0)
        return (int)(computeMagicalSum(0, 0, m, k, nums, n, memo) % MOD);
    }
};
