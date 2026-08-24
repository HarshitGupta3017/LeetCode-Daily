// Solution for Stone Game VIII in CPP

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // prefix[i] = sum of stones[0..i].
        // When a player picks stones up to index i (removing the leftmost i+1 stones),
        // the new stone placed has value prefix[i] — so their net score gain for this
        // move is exactly prefix[i], regardless of how the pile was previously merged.
        vector<int> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + stones[i];

        // dp[i] = best score difference (current player minus opponent) achievable
        // when the current player must choose to pick up to some index j >= i.
        // Base case: if index n-1 is the only choice left, current player scores
        // prefix[n-1] and the game ends — score difference is just prefix[n-1].
        vector<int> dp(n);
        dp[n - 1] = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            // Option 1 — pick up to index i: current player gains prefix[i],
            // then the opponent faces dp[i+1] advantage from the next position.
            // Net difference = prefix[i] - dp[i+1].
            int pickHere = prefix[i] - dp[i + 1];

            // Option 2 — skip index i: let the opponent make the same choice
            // from position i+1 onward, so our advantage carries forward as dp[i+1].
            int skipHere = dp[i + 1];

            dp[i] = max(pickHere, skipHere);
        }

        // The first valid pick is index 1 (must take at least 2 stones — indices 0 and 1),
        // so Alice's first decision starts at i=1.
        return dp[1];
    }
};
