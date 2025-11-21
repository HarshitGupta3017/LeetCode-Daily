// Solution for Unique Length-3 Palindromic Subsequences in CPP

class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n = s.size();

        // For each character 'a' to 'z', store:
        // first position (leftmost)  → firstIndex
        // last position (rightmost)  → lastIndex
        vector<pair<int, int>> charBounds(26, {-1, -1});

        // Step 1: Record first and last appearance of every character
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            // Set leftmost index only once
            if (charBounds[idx].first == -1)
                charBounds[idx].first = i;

            // Always update rightmost index
            charBounds[idx].second = i;
        }

        int result = 0;

        // Step 2: For each character, count distinct middle characters
        for (int c = 0; c < 26; c++) {
            int leftIndex  = charBounds[c].first;
            int rightIndex = charBounds[c].second;

            // If the character doesn't appear, skip
            if (leftIndex == -1)
                continue;

            // Collect all unique characters between the first and last occurrence
            unordered_set<char> middleChars;
            for (int mid = leftIndex + 1; mid < rightIndex; mid++) {
                middleChars.insert(s[mid]);
            }

            // Each unique middle forms a unique palindrome: c _ c
            result += middleChars.size();
        }

        return result;
    }
};
