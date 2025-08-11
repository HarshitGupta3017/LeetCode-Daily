// Solution for Range Product Queries of Powers in CPP

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7; // Modulo value for large numbers

        vector<int> powersOfTwo; // Stores the powers of 2 that sum to n
        vector<int> queryResults; // Final answers for all queries

        // Step 1: Find the powers of two that sum to n
        // Each set bit in n's binary representation corresponds to a power of 2
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if ((n & (1 << bitPosition)) != 0) { // Check if this bit is set
                powersOfTwo.push_back(1 << bitPosition); // Store 2^bitPosition
            }
        }

        // Step 2: Answer each query
        for (const auto& query : queries) {
            int leftIndex = query[0];   // Start index in powersOfTwo
            int rightIndex = query[1];  // End index in powersOfTwo
            long long product = 1;      // Store the product result

            // Multiply all values from leftIndex to rightIndex
            for (int idx = leftIndex; idx <= rightIndex; idx++) {
                product = (product * powersOfTwo[idx]) % MOD;
            }

            queryResults.push_back(product); // Save this query's result
        }

        return queryResults;
    }
};
