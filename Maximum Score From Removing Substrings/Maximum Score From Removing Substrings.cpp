// Solution for Maximum Score From Removing Substrings in CPP

class Solution {
public:
    // Helper function to remove all matching substrings and return remaining string
    string removeSubstr(string s, string& pattern) {
        int i = 0; // write pointer: tracks end of the modified string

        for (int j = 0; j < s.length(); j++) { // read pointer: goes through each character
            s[i] = s[j]; // copy current character to write position
            i++;         // move write pointer ahead

            // Check last two written chars form the pattern
            if (i >= 2 && s[i - 2] == pattern[0] && s[i - 1] == pattern[1]) {
                i -= 2; // remove the matched pattern by rewinding the write pointer
            }
        }

        // Erase the unused part at the end (after last valid char)
        s.erase(s.begin() + i, s.end());
        return s; // return final processed string
    }

    int maximumGain(string s, int x, int y) {
        // Prefer higher scoring pattern first
        string first = x > y ? "ab" : "ba";
        string second = x > y ? "ba" : "ab";

        // Remove first pattern
        string afterFirst = removeSubstr(s, first);
        int firstGain = ((int)s.length() - (int)afterFirst.length()) / 2 * max(x, y);

        // Remove second pattern
        string afterSecond = removeSubstr(afterFirst, second);
        int secondGain = ((int)afterFirst.length() - (int)afterSecond.length()) / 2 * min(x, y);

        return firstGain + secondGain;
    }
};
