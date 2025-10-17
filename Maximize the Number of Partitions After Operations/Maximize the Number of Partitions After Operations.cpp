// Solution for Maximize the Number of Partitions After Operations in CPP

class Solution {
public:
    using ll = long long;
    const int ALPHABET_SIZE = 26;

    /*
     * Helper recursive function to calculate the maximum number of partitions possible.
     *
     * Parameters:
     *   index → current position in string `s`
     *   charMask → bitmask representing distinct characters in the current prefix
     *   canModify → flag indicating if we can still change one character in `s`
     *   s → input string
     *   k → maximum allowed distinct characters per partition
     *   memo → memoization map to avoid recomputation
     *
     * Returns:
     *   maximum number of partitions possible from the current state onward
     */
    int solve(ll index, ll charMask, bool canModify, const string& s, int k,
              unordered_map<ll, int>& memo) {
        
        // Create a compact memoization key by combining multiple states into one number.
        // - index << 27: reserves 27th bit for index (since string length ≤ 10^4)
        // - charMask << 1: stores which characters have appeared so far
        // - canModify: 1 bit indicating whether the one allowed modification is still available
        ll stateKey = (index << 27) | (charMask << 1) | canModify;
        
        // If already computed, return from memo.
        if (memo.count(stateKey)) 
            return memo[stateKey];

        // Base case: if we've processed all characters, no more partitions remain.
        if (index >= s.length()) 
            return 0;

        // Convert current character into its bit position (0 for 'a', 25 for 'z')
        int charBitIndex = s[index] - 'a';

        // Add this character into the current bitmask (marking it as seen)
        int newMask = charMask | (1 << charBitIndex);

        // Count number of unique characters in this current prefix
        int uniqueCount = __builtin_popcount(newMask);

        int maxPartitions;

        /*
         * CASE 1️⃣: Without changing the current character
         *
         * If adding this character exceeds `k` distinct characters,
         * we must end the current partition here and start a new one.
         */
        if (uniqueCount > k) {
            // Start new partition: reset the bitmask to current character only
            maxPartitions = 1 + solve(index + 1, (1 << charBitIndex), canModify, s, k, memo);
        } else {
            // Continue current partition with updated distinct set
            maxPartitions = solve(index + 1, newMask, canModify, s, k, memo);
        }

        /*
         * CASE 2️⃣: Use the one allowed character change (if available)
         * Try replacing s[index] with any letter 'a' to 'z' and simulate outcomes.
         */
        if (canModify) {
            for (int replacement = 0; replacement < ALPHABET_SIZE; replacement++) {
                int modifiedMask = charMask | (1 << replacement);
                int modifiedUniqueCount = __builtin_popcount(modifiedMask);

                if (modifiedUniqueCount > k) {
                    // Replacement causes a new partition (exceeds k distinct)
                    maxPartitions = max(maxPartitions,
                        1 + solve(index + 1, (1 << replacement), false, s, k, memo));
                } else {
                    // Continue in same partition with modified character
                    maxPartitions = max(maxPartitions,
                        solve(index + 1, modifiedMask, false, s, k, memo));
                }
            }
        }

        // Store computed result in memo table
        return memo[stateKey] = maxPartitions;
    }

    /*
     * Main function: computes maximum partitions after optimal single-character change.
     */
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<ll, int> memo;
        // +1 because even if recursion counts only transitions,
        // there is always one partition left at the end.
        return solve(0, 0, true, s, k, memo) + 1;
    }
};
