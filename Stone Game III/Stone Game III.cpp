// Solution for Stone Game III in CPP

class Solution {
public:
    string stoneGameIII(vector<int>& stoneGame) {
        int n = stoneGame.size();

        // Space-optimised version of the DP: since dp[i] only ever looks at
        // dp[i+1], dp[i+2], and dp[i+3], we only need to keep three variables
        // instead of an n+1 array.
        // nextOne   = dp[i+1] (advantage if the current player skips 1 stone)
        // nextTwo   = dp[i+2] (advantage if the current player skips 2 stones)
        // nextThree = dp[i+3] (advantage if the current player skips 3 stones)
        int nextOne = 0, nextTwo = 0, nextThree = 0;

        for (int i = n - 1; i >= 0; i--) {
            int taken = stoneGame[i];

            // Take 1 stone: opponent plays from i+1, their advantage is nextOne.
            int best = taken - nextOne;

            // Take 2 stones: only valid if i+2 is within bounds.
            if (i + 2 <= n) {
                taken += stoneGame[i + 1];
                best = max(best, taken - nextTwo);
            }

            // Take 3 stones: only valid if i+3 is within bounds.
            if (i + 3 <= n) {
                taken += stoneGame[i + 2];
                best = max(best, taken - nextThree);
            }

            // Slide the window: what was i+1, i+2 becomes i+2, i+3 for the next iteration.
            nextThree = nextTwo;
            nextTwo   = nextOne;
            nextOne   = best;
        }

        // After the loop, nextOne holds dp[0] — Alice's advantage over Bob.
        int aliceAdvantage = nextOne;
        if (aliceAdvantage > 0) return "Alice";
        if (aliceAdvantage < 0) return "Bob";
        return "Tie";
    }
};
