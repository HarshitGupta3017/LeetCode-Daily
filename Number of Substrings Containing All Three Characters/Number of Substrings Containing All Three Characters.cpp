// Solution for Number of Substrings Containing All Three Characters in CPP

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0, result = 0;
        int n = s.length();

        // freq tracks how many times each of 'a', 'b', 'c' currently appears
        // in the window [left, right]. Once all three are present, the window
        // is "valid" — shrinking it further determines the smallest valid window.
        unordered_map<char, int> freq;

        while (right < n) {
            freq[s[right]]++;

            // Once the window contains all 3 distinct characters, every substring
            // that starts at 'left' and ends anywhere from 'right' to the end of
            // the string also contains all 3 characters (extending the right end
            // can only keep characters present, never remove them).
            // That gives (n - right) valid substrings for this left position.
            while (freq.size() == 3) {
                result += n - right;

                // Shrink from the left to find the next smallest valid window,
                // removing characters once their count drops to zero so freq.size()
                // accurately reflects which characters are still present.
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }

            right++;
        }

        return result;
    }
};
