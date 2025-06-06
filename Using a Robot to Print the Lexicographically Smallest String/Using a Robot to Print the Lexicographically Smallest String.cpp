// Solution for Using a Robot to Print the Lexicographically Smallest String in CPP

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        // Step 1: Compute the minimum character to the right (including self) for each index
        vector<char> minRight(n);  // minRight[i] stores the smallest char from s[i] to s[n-1]
        minRight[n - 1] = s[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minRight[i] = min(s[i], minRight[i + 1]);
        }

        string robotBuffer;  // Represents string t held by the robot
        string paper;        // Final result that gets written on the paper

        for (int i = 0; i < n; ++i) {
            robotBuffer.push_back(s[i]);  // Operation 1: move from s to t

            // Find the minimum character that still remains in s (after current position)
            char smallestRemaining = (i + 1 < n) ? minRight[i + 1] : s[i];

            // Operation 2: keep popping from t to paper while it's lex smaller or equal
            while (!robotBuffer.empty() && robotBuffer.back() <= smallestRemaining) {
                paper += robotBuffer.back();  // write to paper
                robotBuffer.pop_back();       // remove from t
            }
        }

        // After processing all of s, flush remaining characters in t to paper
        while (!robotBuffer.empty()) {
            paper += robotBuffer.back();
            robotBuffer.pop_back();
        }

        return paper;
    }
};
