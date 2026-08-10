// Solution for Stone Game IV in JAVA

class Solution {
    // Returns true if the current player can guarantee a win
    // with exactly 'remaining' stones left.
    private boolean solve(int remaining, int[] memo) {
        // No stones left → current player loses.
        if (remaining == 0) {
            return false;
        }

        if (memo[remaining] != -1) {
            return memo[remaining] == 1;
        }

        // Try removing every perfect square <= remaining.
        for (int k = 1; k * k <= remaining; k++) {
            if (!solve(remaining - k * k, memo)) {
                memo[remaining] = 1;
                return true;
            }
        }

        // No winning move found.
        memo[remaining] = 0;
        return false;
    }

    public boolean winnerSquareGame(int n) {
        int[] memo = new int[n + 1];
        java.util.Arrays.fill(memo, -1);

        return solve(n, memo);
    }
}
