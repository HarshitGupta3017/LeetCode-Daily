// Solution for Count Partitions with Even Sum Difference in CPP

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        // ---------------------------------------------
        // STEP 1: Compute the total sum of the array.
        // The parity (even/odd) of this total alone
        // determines whether any valid partition exists.
        // ---------------------------------------------
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // ---------------------------------------------
        // STEP 2: Analyze parity.
        //
        // For any partition i:
        //   leftSum  = x
        //   rightSum = totalSum - x
        //
        // Required: (leftSum - rightSum) is even
        //           => (2x - totalSum) is even
        //           => parity depends ONLY on totalSum
        //
        // If totalSum is even:
        //     Every partition (n - 1 choices) is valid.
        //
        // If totalSum is odd:
        //     No partition will ever produce an even difference.
        // ---------------------------------------------
        if (totalSum % 2 == 0) {
            // All partitions valid → there are (n - 1) partitions
            return nums.size() - 1;
        }

        // Odd total sum → zero valid partitions
        return 0;
    }
};
