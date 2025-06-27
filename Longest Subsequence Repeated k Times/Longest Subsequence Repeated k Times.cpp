// Solution for Longest Subsequence Repeated k Times in CPP

class Solution {
public:

    // Helper to check if 'sub' repeated k times is a subsequence of 's'
    bool isSubsequence(string& s, string& sub, int k) {
        int i = 0, j = 0;
        int len = sub.length();
        int n = s.length();
        while (i < n && j < len * k) {
            if (s[i] == sub[j % len]) {
                j++;
            }
            i++;
        }
        return j == len * k;
    }

    // Backtracking to generate lexicographically largest string of maxLen using available characters
    bool backtrack(string& s, string& curr, vector<bool>& usable, vector<int>& remainingFreq, int maxLen, int k, string& result) {
        if (curr.length() == maxLen) {
            // Check if current candidate repeated k times is valid subsequence
            if (isSubsequence(s, curr, k)) {
                result = curr;
                return true;
            }
            return false;
        }

        // Try characters from 'z' to 'a' to ensure lexicographically largest first
        for (int i = 25; i >= 0; i--) {
            if (!usable[i] || remainingFreq[i] == 0) continue;
            char ch = i + 'a';
            curr.push_back(ch);
            remainingFreq[i]--;

            if (backtrack(s, curr, usable, remainingFreq, maxLen, k, result))
                return true;

            // Backtrack
            curr.pop_back();
            remainingFreq[i]++;
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Determine which characters are usable (appear at least k times)
        vector<bool> usable(26, false);
        vector<int> maxAvailable(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                usable[i] = true;
                maxAvailable[i] = freq[i] / k;
            }
        }

        int maxPossibleLength = n / k;
        string result = "";

        // Try decreasing lengths until a valid one is found
        for (int len = maxPossibleLength; len >= 0; len--) {
            vector<int> remainingFreq = maxAvailable;
            string curr = "";
            if (backtrack(s, curr, usable, remainingFreq, len, k, result))
                return result;
        }

        return result;
    }
};
