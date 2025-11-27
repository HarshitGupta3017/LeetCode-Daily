// Solution for Maximum Subarray Sum With Length Divisible by K in CPP

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        // -----------------------------
        // Prefix Sum to compute any subarray sum in O(1)
        // prefixSum[i] = sum of nums[0..i]
        // -----------------------------
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        long long bestResult = LLONG_MIN;

        /*
            Key Observation:
            ----------------
            A subarray length must be divisible by k.
            That means valid subarrays start at indices:

                start = 0, 1, 2, ... , k-1

            Example for k = 3:
            start = 0 → take lengths 3, 6, 9 ...
            start = 1 → take lengths 3, 6, 9 ...
            start = 2 → take lengths 3, 6, 9 ...

            For each starting point, we repeatedly jump by k
            (i → i + k → i + 2k ...) and treat each group like
            a "Kadane's algorithm on chunks of size k".
        */

        for (int startIndex = 0; startIndex < k; startIndex++) {

            long long bestEndingHere = 0;  // Kadane's rolling sum
            int i = startIndex;

            while (i < n && (i + k - 1) < n) {

                // Ending index of this fixed-size subarray
                int endIndex = i + k - 1;

                // Compute subarray sum(nums[i..endIndex]) using prefix sums
                long long blockSum =
                    prefixSum[endIndex] - (i > 0 ? prefixSum[i - 1] : 0);

                /*
                    Update Kadane:
                    Either:
                     - Start a new subarray from this block
                     - Or extend previous sequence by adding this block
                */
                bestEndingHere = max(blockSum, bestEndingHere + blockSum);

                // Track global maximum
                bestResult = max(bestResult, bestEndingHere);

                // Move to next block of size k
                i += k;
            }
        }

        return bestResult;
    }
};
