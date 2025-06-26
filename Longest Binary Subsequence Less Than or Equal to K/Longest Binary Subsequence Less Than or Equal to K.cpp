// Solution for Longest Binary Subsequence Less Than or Equal to K in CPP

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        long long powerOfTwo = 1;  // Represents 2^0 initially
        int maxLength = 0;         // Final length of the valid subsequence

        // Traverse the binary string from right to left (least significant bit to most)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                // Always safe to include '0' since it doesn't increase the value
                maxLength++;
            } else if (powerOfTwo <= k) {
                // Include '1' only if its value doesn't exceed remaining k
                k -= powerOfTwo;
                maxLength++;
            }

            // Prepare next power of 2 for leftward bit (e.g., 2^1, 2^2, ...)
            // But avoid overflow and unnecessary growth beyond k
            if (powerOfTwo <= k) {
                powerOfTwo <<= 1; // Equivalent to powerOfTwo *= 2
            }
        }

        return maxLength;
    }
};
