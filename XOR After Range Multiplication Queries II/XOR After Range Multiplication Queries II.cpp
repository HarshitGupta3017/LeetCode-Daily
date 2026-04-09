// Solution for XOR After Range Multiplication Queries II in CPP

class Solution {
public:

    using ll = long long;
    const int MOD = 1e9 + 7;

    /*
    ============================================================
    Fast exponentiation (Binary Exponentiation)
    Used for modular inverse via Fermat's theorem
    ============================================================
    */
    ll power(ll base, ll exponent) {
        if (exponent == 0) return 1;

        ll half = power(base, exponent / 2);
        ll result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        /*
        ============================================================
        Sqrt Decomposition Threshold
        ============================================================

        Large K → simulate directly
        Small K → optimize using grouping
        */
        int blockSize = ceil(sqrt(n));

        /*
        Store queries grouped by small step size K
        */
        unordered_map<int, vector<vector<int>>> smallKQueries;

        /*
        ============================================================
        STEP 1: Process LARGE K directly
        ============================================================
        */
        for (const auto& query : queries) {

            int left = query[0];
            int right = query[1];
            int step = query[2];
            int multiplier = query[3];

            /*
            ------------------------------------------------------------
            If step is large → number of affected indices is small
            → direct simulation is efficient
            ------------------------------------------------------------
            */
            if (step >= blockSize) {

                for (int index = left; index <= right; index += step) {
                    nums[index] = (1LL * nums[index] * multiplier) % MOD;
                }
            } 
            else {
                /*
                Small K → store for batch processing
                */
                smallKQueries[step].push_back(query);
            }
        }

        /*
        ============================================================
        STEP 2: Process SMALL K using Difference Trick
        ============================================================
        */
        for (auto& [step, queriesWithSameStep] : smallKQueries) {

            /*
            diff[i] → cumulative multiplier for index i
            Initialized with 1 (neutral element for multiplication)
            */
            vector<ll> diff(n, 1);

            /*
            ------------------------------------------------------------
            Mark ranges in diff array
            ------------------------------------------------------------
            */
            for (auto& query : queriesWithSameStep) {

                int left = query[0];
                int right = query[1];
                int multiplier = query[3];

                /*
                Start multiplying from left
                */
                diff[left] = (diff[left] * multiplier) % MOD;

                /*
                Compute first index OUTSIDE the valid range
                */
                int stepsCount = (right - left) / step;
                int nextIndex = left + (stepsCount + 1) * step;

                /*
                Stop multiplication beyond range using modular inverse
                */
                if (nextIndex < n) {
                    diff[nextIndex] = (diff[nextIndex] * power(multiplier, MOD - 2)) % MOD;
                }
            }

            /*
            ------------------------------------------------------------
            Build prefix-like multiplication for step spacing
            ------------------------------------------------------------
            */
            for (int i = 0; i < n; i++) {

                if (i - step >= 0) {
                    diff[i] = (diff[i] * diff[i - step]) % MOD;
                }
            }

            /*
            ------------------------------------------------------------
            Apply accumulated multipliers to nums
            ------------------------------------------------------------
            */
            for (int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }

        /*
        ============================================================
        STEP 3: Compute XOR of final array
        ============================================================
        */
        int finalXOR = 0;

        for (const auto& value : nums) {
            finalXOR ^= value;
        }

        return finalXOR;
    }
};
