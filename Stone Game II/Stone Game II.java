// Solution for Stone Game II in JAVA

class Solution {
    int[][][] memo;

    int solve(int[] piles, boolean isAliceTurn, int idx, int maxPiles, int n) {
        if (idx >= n) {
            return 0;
        }

        int turn = isAliceTurn ? 1 : 0;

        if (memo[turn][idx][maxPiles] != -1) {
            return memo[turn][idx][maxPiles];
        }

        int best = isAliceTurn ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        int stonesSoFar = 0;

        for (int x = 1; x <= Math.min(2 * maxPiles, n - idx); x++) {
            stonesSoFar += piles[idx + x - 1];

            int aliceFromHere = solve(
                piles,
                !isAliceTurn,
                idx + x,
                Math.max(maxPiles, x),
                n
            );

            if (isAliceTurn) {
                best = Math.max(best, stonesSoFar + aliceFromHere);
            } else {
                best = Math.min(best, aliceFromHere);
            }
        }

        return memo[turn][idx][maxPiles] = best;
    }

    public int stoneGameII(int[] piles) {
        int n = piles.length;

        memo = new int[2][n][n + 1];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                java.util.Arrays.fill(memo[i][j], -1);
            }
        }

        return solve(piles, true, 0, 1, n);
    }
}
