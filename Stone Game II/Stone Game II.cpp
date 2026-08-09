// Solution for Stone Game II in CPP

class Solution {
public:
    // Returns Alice's maximum stones from piles[idx..n-1], given:
    // - isAliceTurn: true if it's Alice's turn, false if Bob's
    // - maxPiles: the current value of M (max piles taken in any prior turn)
    // Alice maximises her total; Bob plays to minimise Alice's total (zero-sum).
    int solve(vector<int>& piles, bool isAliceTurn, int idx, int maxPiles, int n,
              vector<vector<vector<int>>>& memo) {
        if (idx >= n) return 0;

        int turn = isAliceTurn ? 1 : 0;
        if (memo[turn][idx][maxPiles] != -1)
            return memo[turn][idx][maxPiles];

        // Alice wants to maximise; Bob wants to minimise Alice's score.
        int best = isAliceTurn ? INT_MIN : INT_MAX;
        int stonesSoFar = 0;

        for (int x = 1; x <= min(2 * maxPiles, n - idx); x++) {
            stonesSoFar += piles[idx + x - 1];
            int aliceFromHere = solve(piles, !isAliceTurn, idx + x, max(maxPiles, x), n, memo);

            if (isAliceTurn)
                // Alice takes `stonesSoFar` now and then gets whatever she secures later.
                best = max(best, stonesSoFar + aliceFromHere);
            else
                // Bob takes these stones (not added to Alice's total); we track only
                // what Alice accumulates, so Bob's turn just passes through aliceFromHere.
                best = min(best, aliceFromHere);
        }

        return memo[turn][idx][maxPiles] = best;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // Dimensions: [whose turn: 0=Bob,1=Alice] x [pile index] x [M value]
        vector<vector<vector<int>>> memo(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return solve(piles, true, 0, 1, n, memo);
    }
};
