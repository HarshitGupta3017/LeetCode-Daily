// Solution for Trionic Array II in CPP

// trend meanings:
// 0 -> haven't started the trionic subarray yet
// 1 -> first strictly increasing phase
// 2 -> strictly decreasing phase
// 3 -> final strictly increasing phase (valid trionic if we end here)

class Solution {
public:
    using ll = long long;

    // Recursive DP function
    // index        -> current position in nums
    // trend        -> current phase of trionic sequence (0 to 3)
    // nums         -> input array
    // memo         -> memoization table
    ll dfsMaxSum(
        int index,
        int trend,
        vector<int>& nums,
        vector<vector<ll>>& memo
    ) {
        int n = nums.size();

        // Base case: reached the end of the array
        // Valid only if we have completed all 3 phases (trend == 3)
        if (index == n) {
            return (trend == 3) ? 0 : LLONG_MIN / 2;
        }

        // Return cached result if already computed
        if (memo[index][trend] != LLONG_MIN) {
            return memo[index][trend];
        }

        // Option 1: take current element
        ll takeCurrent = LLONG_MIN / 2;

        // Option 2: skip current element
        ll skipCurrent = LLONG_MIN / 2;

        // We are allowed to skip elements ONLY before starting the sequence
        if (trend == 0) {
            skipCurrent = dfsMaxSum(index + 1, 0, nums, memo);
        }

        // If we are already in the final increasing phase,
        // we can always keep taking elements
        if (trend == 3) {
            takeCurrent = nums[index];
        }

        // Try transitions based on the next element
        if (index + 1 < n) {
            int currentValue = nums[index];
            int nextValue = nums[index + 1];

            // Phase 0 -> Phase 1 (start first increasing)
            if (trend == 0 && nextValue > currentValue) {
                takeCurrent = max(
                    takeCurrent,
                    currentValue + dfsMaxSum(index + 1, 1, nums, memo)
                );
            }

            // Phase 1: strictly increasing
            else if (trend == 1) {
                // Continue increasing
                if (nextValue > currentValue) {
                    takeCurrent = max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 1, nums, memo)
                    );
                }
                // Switch to decreasing phase
                else if (nextValue < currentValue) {
                    takeCurrent = max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 2, nums, memo)
                    );
                }
            }

            // Phase 2: strictly decreasing
            else if (trend == 2) {
                // Continue decreasing
                if (nextValue < currentValue) {
                    takeCurrent = max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 2, nums, memo)
                    );
                }
                // Switch to final increasing phase
                else if (nextValue > currentValue) {
                    takeCurrent = max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 3, nums, memo)
                    );
                }
            }

            // Phase 3: final increasing phase
            else if (trend == 3 && nextValue > currentValue) {
                takeCurrent = max(
                    takeCurrent,
                    currentValue + dfsMaxSum(index + 1, 3, nums, memo)
                );
            }
        }

        // Store and return the best result from this state
        return memo[index][trend] = max(takeCurrent, skipCurrent);
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        // memo[index][trend] stores the maximum sum
        // starting from index with the given trend
        vector<vector<ll>> memo(n + 1, vector<ll>(4, LLONG_MIN));

        // Start from index 0 with trend 0 (not started yet)
        return dfsMaxSum(0, 0, nums, memo);
    }
};
