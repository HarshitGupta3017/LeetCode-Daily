// Solution for Longest Balanced Substring I in CPP

class Solution {
public:
    int longestBalanced(string s) {

        int n = s.size();

        /*
            Stores maximum length of any balanced substring.
        */
        int maxLength = 0;

        /*
            Helper function:
            Checks whether all NON-ZERO frequencies
            in the current frequency array are equal.

            Balanced condition:
            All distinct characters appear
            exactly the same number of times.
        */
        auto isBalanced = [](const vector<int>& freq) {

            int requiredFrequency = 0;

            for (int i = 0; i < 26; i++) {

                if (freq[i] == 0)
                    continue;  // ignore unused characters

                if (requiredFrequency == 0) {
                    // first seen character frequency
                    requiredFrequency = freq[i];
                }
                else if (freq[i] != requiredFrequency) {
                    // mismatch found
                    return false;
                }
            }

            return true;
        };

        /*
            Fix starting index of substring.
            Expand right pointer and keep updating frequency.
        */
        for (int start = 0; start < n; start++) {

            // frequency of characters in current substring
            vector<int> frequency(26, 0);

            for (int end = start; end < n; end++) {

                // Update frequency for current character
                frequency[s[end] - 'a']++;

                /*
                    After adding current character,
                    check if substring [start ... end]
                    satisfies balanced condition.
                */
                if (isBalanced(frequency)) {
                    maxLength = max(maxLength, end - start + 1);
                }
            }
        }

        return maxLength;
    }
};
