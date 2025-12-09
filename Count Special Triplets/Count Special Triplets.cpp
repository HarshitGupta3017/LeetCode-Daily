// Solution for Count Special Triplets in CPP

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // Frequency maps:
        // freqLeft[x]  -> count of x on the left side of current j
        // freqRight[x] -> count of x on the right side of current j
        unordered_map<int, long long> freqLeft;
        unordered_map<int, long long> freqRight;

        const int MOD = 1e9 + 7;
        long long totalTriplets = 0;

        // ---------------------------------------------
        // STEP 1: Initially, every element is on the RIGHT.
        // We'll move j from left to right, shifting counts.
        // ---------------------------------------------
        for (int num : nums) {
            freqRight[num]++;
        }

        // ---------------------------------------------
        // STEP 2: Iterate each index as potential 'j'
        // ---------------------------------------------
        for (int currentValue : nums) {

            // Remove currentValue from RIGHT because j is no longer on right side
            freqRight[currentValue]--;

            // The condition requires:
            // nums[i] == 2 * nums[j]
            // nums[k] == 2 * nums[j]
            long long requiredValue = 2LL * currentValue;

            // Count valid i on left side
            long long countLeftMatches = freqLeft[requiredValue];

            // Count valid k on right side
            long long countRightMatches = freqRight[requiredValue];

            // Multiply combinations for this j
            totalTriplets = (totalTriplets + (countLeftMatches * countRightMatches) % MOD) % MOD;

            // Now current j moves into LEFT for future iterations
            freqLeft[currentValue]++;
        }

        return totalTriplets % MOD;
    }
};
