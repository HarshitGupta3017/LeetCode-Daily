// Solution for Maximum Length Substring With Two Occurrences in CPP

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0, right = 0;
        int maxLen = 0;
        vector<int> freq(26, 0);

        while (right < (int)s.size()) {
            freq[s[right] - 'a']++;

            // If the character just added now appears more than twice,
            // shrink the window from the left until its count is back to 2.
            // Only the rightmost character can be the violator since all
            // previous window characters were already within the limit.
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
