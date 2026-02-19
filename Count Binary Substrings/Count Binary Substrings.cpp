// Solution for Count Binary Substrings in CPP

class Solution {
public:
    int countBinarySubstrings(string s) {
        int totalSubstrings = 0;

        // Length of the previous consecutive group (e.g., "000")
        int previousGroupLength = 0;

        // Length of the current consecutive group
        int currentGroupLength = 1;   // Start with 1 because first char forms a group

        // Start from second character
        for (int i = 1; i < s.size(); i++) {

            if (s[i] == s[i - 1]) {
                // Still in the same group → increase current group length
                currentGroupLength++;
            } else {
                // Group changed (e.g., from 0s to 1s or 1s to 0s)

                // We can form substrings equal to:
                // min(previous group size, current group size)
                totalSubstrings += min(previousGroupLength, currentGroupLength);

                // Shift current group to previous
                previousGroupLength = currentGroupLength;

                // Reset current group length for new character
                currentGroupLength = 1;
            }
        }

        // Add the last pair of groups
        totalSubstrings += min(previousGroupLength, currentGroupLength);

        return totalSubstrings;
    }
};
