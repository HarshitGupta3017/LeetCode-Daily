// Solution for Find the Lexicographically Smallest Valid Sequence in CPP

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // Precompute suffixMatchCount[i] = number of characters of word2 that can be
        // matched by scanning word1[i..n-1] from right to left.
        // This tells us: if we've already matched word2[0..j-1] from the left,
        // can the remaining word2[j..m-1] still be matched from position i onward?
        vector<int> suffixMatchCount(n, 0);
        int suffixMatched = 0;
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                suffixMatched++;
                j--;
            }
            suffixMatchCount[i] = suffixMatched;
        }

        // Greedily build the index sequence from left to right.
        // We match word2[j] with the earliest possible word1[i] to keep the
        // sequence lexicographically smallest.
        vector<int> seq;
        bool canUseMismatch = true; // we're allowed at most one substitution
        j = 0;

        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                // Exact match — always take it greedily.
                seq.push_back(i);
                j++;
            }
            else if (canUseMismatch && i + 1 < n && suffixMatchCount[i + 1] >= m - j - 1) {
                // Use our one allowed substitution here: word1[i] replaces word2[j].
                // We only do this if the remaining word2[j+1..m-1] can still be
                // matched exactly by word1[i+1..n-1] (verified via suffixMatchCount).
                // This ensures the substitution doesn't make the rest impossible.
                seq.push_back(i);
                j++;
                canUseMismatch = false;
            }
        }

        // If we matched all of word2 (possibly with one substitution), return the sequence.
        // Otherwise no valid sequence exists.
        return (j == m) ? seq : vector<int>();
    }
};
