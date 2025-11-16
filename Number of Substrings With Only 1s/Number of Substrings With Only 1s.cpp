// Solution for Number of Substrings With Only 1s in CPP

class Solution {
public:

    const int MOD = 1e9 + 7;

    int numSub(string s) {

        int totalSubstrings = 0;   // Stores the final count of all-1 substrings
        int consecutiveOnes = 0;   // Tracks current streak of continuous '1' characters

        // 🔹 Iterate through each character in the string
        for (char ch : s) {

            if (ch == '1') {
                // Extend the streak of '1's
                consecutiveOnes++;

                // Add contribution of this new '1':
                // Every time we add a '1' to a streak, it forms:
                //   +1 substring of length 1
                //   +1 substring of length 2
                //   ... up to the current streak length
                // Meaning: total += consecutiveOnes
                totalSubstrings = (totalSubstrings + consecutiveOnes) % MOD;
            }
            else {
                // Reset streak when encountering '0'
                consecutiveOnes = 0;
            }
        }

        return totalSubstrings;
    }
};
