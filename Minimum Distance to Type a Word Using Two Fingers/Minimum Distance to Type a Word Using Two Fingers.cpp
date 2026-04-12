// Solution for Minimum Distance to Type a Word Using Two Fingers in CPP

class Solution {
public:
    // DP State:
    // dp[index][finger1Pos][finger2Pos]
    // -> Minimum cost to type substring starting from 'index'
    //    with finger1 at 'finger1Pos' and finger2 at 'finger2Pos'
    int dp[301][27][27];

    // Helper to compute Manhattan distance between two characters
    int getDistance(int fromChar, int toChar) {
        // Convert character index (0–25) into grid coordinates
        auto [x1, y1] = make_pair(fromChar / 6, fromChar % 6);
        auto [x2, y2] = make_pair(toChar / 6, toChar % 6);

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string& word, int index, int finger1Pos, int finger2Pos) {
        // Base case: all characters typed
        if (index >= word.size()) return 0;

        // Return memoized result if already computed
        if (dp[index][finger1Pos][finger2Pos] != -1)
            return dp[index][finger1Pos][finger2Pos];

        // Current character to type (0–25)
        int currentCharIndex = word[index] - 'A';

        // Case 1: Both fingers are unused (initial state)
        if (finger1Pos == 26 && finger2Pos == 26) {
            // Assign first character to finger1 (cost = 0 since initial placement is free)
            return dp[index][finger1Pos][finger2Pos] =
                solve(word, index + 1, currentCharIndex, finger2Pos);
        }

        // Case 2: Only finger2 is unused
        if (finger2Pos == 26) {
            // Option 1: Use finger2 (free placement)
            int useFinger2 = solve(word, index + 1, finger1Pos, currentCharIndex);

            // Option 2: Move finger1 to current character
            int useFinger1 = getDistance(finger1Pos, currentCharIndex) +
                             solve(word, index + 1, currentCharIndex, finger2Pos);

            return dp[index][finger1Pos][finger2Pos] =
                min(useFinger2, useFinger1);
        }

        // Case 3: Both fingers are already placed

        // Option 1: Move finger1 to type current character
        int moveFinger1 = getDistance(finger1Pos, currentCharIndex) +
                          solve(word, index + 1, currentCharIndex, finger2Pos);

        // Option 2: Move finger2 to type current character
        int moveFinger2 = getDistance(finger2Pos, currentCharIndex) +
                          solve(word, index + 1, finger1Pos, currentCharIndex);

        // Take minimum of both choices
        return dp[index][finger1Pos][finger2Pos] =
            min(moveFinger1, moveFinger2);
    }

    int minimumDistance(string word) {
        // Initialize DP table with -1 (uncomputed states)
        memset(dp, -1, sizeof(dp));

        // 26 represents "finger not placed yet"
        return solve(word, 0, 26, 26);
    }
};
