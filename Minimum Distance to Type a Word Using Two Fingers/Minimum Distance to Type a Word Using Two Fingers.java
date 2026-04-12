// Solution for Minimum Distance to Type a Word Using Two Fingers in JAVA

class Solution {
    // dp[index][finger1][finger2]
    int[][][] dp = new int[301][27][27];

    // Manhattan distance
    int getDistance(int fromChar, int toChar) {
        int x1 = fromChar / 6, y1 = fromChar % 6;
        int x2 = toChar / 6, y2 = toChar % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    int solve(String word, int index, int f1, int f2) {
        if (index >= word.length()) return 0;

        if (dp[index][f1][f2] != -1)
            return dp[index][f1][f2];

        int curr = word.charAt(index) - 'A';

        // Case 1: both unused
        if (f1 == 26 && f2 == 26) {
            return dp[index][f1][f2] =
                solve(word, index + 1, curr, f2);
        }

        // Case 2: finger2 unused
        if (f2 == 26) {
            int useF2 = solve(word, index + 1, f1, curr);

            int useF1 = getDistance(f1, curr) +
                        solve(word, index + 1, curr, f2);

            return dp[index][f1][f2] = Math.min(useF2, useF1);
        }

        // Case 3: both used
        int moveF1 = getDistance(f1, curr) +
                     solve(word, index + 1, curr, f2);

        int moveF2 = getDistance(f2, curr) +
                     solve(word, index + 1, f1, curr);

        return dp[index][f1][f2] = Math.min(moveF1, moveF2);
    }

    public int minimumDistance(String word) {
        for (int i = 0; i < 301; i++) {
            for (int j = 0; j < 27; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        return solve(word, 0, 26, 26);
    }
}
