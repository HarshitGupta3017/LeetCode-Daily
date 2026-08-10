// Solution for Stone Game IV in CPP

class Solution {
public:
    // Returns true if the player whose turn it is can guarantee a win
    // with exactly `remaining` stones left in the pile.
    // A position is winning if there exists at least one move that leaves
    // the opponent in a losing position.
    bool solve(int remaining, vector<int>& memo) {
        // No stones left → current player cannot move → current player loses.
        if (remaining == 0) return false;

        if (memo[remaining] != -1) return memo[remaining] == 1;

        // Try removing every perfect square k² ≤ remaining.
        // If any such move leaves the opponent in a losing position, we win.
        for (int k = 1; k * k <= remaining; k++) {
            if (!solve(remaining - k * k, memo))
                return memo[remaining] = true;
        }

        // No move leads to a losing position for the opponent → current player loses.
        return memo[remaining] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};
