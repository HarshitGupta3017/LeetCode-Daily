// Solution for Shortest and Lexicographically Smallest Beautiful String in CPP

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        int onesCount = 0;
        string best = "";

        while (right < n) {
            if (s[right] == '1') onesCount++;

            // Shrink from the left to maintain at most k ones in the window,
            // and to eliminate any leading zeros (they only increase length
            // without contributing to the ones count — always wasteful).
            while (onesCount > k || s[left] == '0') {
                if (s[left] == '1') onesCount--;
                left++;
            }

            // The window [left, right] now has exactly k ones with no leading zeros.
            // It is a candidate beautiful substring of the minimum possible length
            // for its right boundary.
            if (onesCount == k) {
                string candidate = s.substr(left, right - left + 1);

                if (best.empty()
                    || candidate.size() < best.size()
                    || (candidate.size() == best.size() && candidate < best)) {
                    best = candidate;
                }
            }

            right++;
        }

        return best;
    }
};
