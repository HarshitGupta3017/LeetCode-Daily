// Solution for XOR After Range Multiplication Queries I in CPP

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        const int MOD = 1e9 + 7;

        /*
        ============================================================
        STEP 1: Process each query
        ============================================================

        Each query:
        [leftIndex, rightIndex, stepSize, multiplier]

        We start from leftIndex and keep jumping by stepSize
        until we cross rightIndex
        */

        for (const auto& query : queries) {

            int leftIndex = query[0];
            int rightIndex = query[1];
            int stepSize = query[2];
            int multiplier = query[3];

            /*
            ------------------------------------------------------------
            Apply updates on indices:
            leftIndex, leftIndex + stepSize, leftIndex + 2*stepSize, ...
            ------------------------------------------------------------
            */
            int currentIndex = leftIndex;

            while (currentIndex <= rightIndex) {

                /*
                Multiply current element and take modulo
                */
                nums[currentIndex] = (1LL * nums[currentIndex] * multiplier) % MOD;

                /*
                Move to next valid index in this query
                */
                currentIndex += stepSize;
            }
        }

        /*
        ============================================================
        STEP 2: Compute XOR of final array
        ============================================================
        */
        int finalXOR = 0;

        for (int value : nums) {
            finalXOR ^= value;
        }

        return finalXOR;
    }
};
