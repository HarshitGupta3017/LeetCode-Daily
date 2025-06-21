// Solution for Minimum Deletions to Make String K-Special in CPP

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> charFrequency(26, 0);

        // Count frequency of each character
        for (char ch : word) {
            charFrequency[ch - 'a']++;
        }

        // Sort frequencies in increasing order
        sort(charFrequency.begin(), charFrequency.end());

        int minDeletions = INT_MAX;
        int cumulativeDeletions = 0;

        // Try to fix each frequency freq[i] as the minimum allowed frequency
        for (int i = 0; i < 26; i++) {
            int deletionsNeeded = cumulativeDeletions;

            // Try to reduce all frequencies greater than freq[i] + k
            for (int j = 25; j > i; j--) {
                if (charFrequency[j] - charFrequency[i] <= k) break;
                deletionsNeeded += charFrequency[j] - charFrequency[i] - k;
            }

            minDeletions = min(minDeletions, deletionsNeeded);
            cumulativeDeletions += charFrequency[i]; // Delete all of freq[i] if moving forward
        }

        return minDeletions;
    }
};
