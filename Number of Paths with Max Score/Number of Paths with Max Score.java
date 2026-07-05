// Solution for Number of Paths with Max Score in JAVA

class Solution {
    int n;
    static final int MOD = 1_000_000_007;
    int[][] scoreMemo, pathMemo;

    private int digit(char ch) {
        return ch == 'S' ? 0 : ch - '0';
    }

    private boolean valid(int i, int j, List<String> board) {
        return i >= 0 && j >= 0 && i < n && j < n && board.get(i).charAt(j) != 'X';
    }

    private int[] solve(int i, int j, List<String> board) {
        char ch = board.get(i).charAt(j);

        if (ch == 'E') return new int[]{0, 1};
        if (ch == 'X') return new int[]{0, 0};

        if (scoreMemo[i][j] != -1)
            return new int[]{scoreMemo[i][j], pathMemo[i][j]};

        int[][] dirs = {{-1, 0}, {0, -1}, {-1, -1}};
        int bestScore = 0, bestPaths = 0;

        for (int[] d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (!valid(ni, nj, board)) continue;

            int[] res = solve(ni, nj, board);
            int score = res[1] > 0 ? res[0] + digit(ch) : 0;

            if (score > bestScore) {
                bestScore = score;
                bestPaths = res[1];
            } else if (score == bestScore && res[1] > 0) {
                bestPaths = (bestPaths + res[1]) % MOD;
            }
        }

        if (bestPaths == 0) bestScore = 0;

        scoreMemo[i][j] = bestScore;
        pathMemo[i][j] = bestPaths;

        return new int[]{bestScore, bestPaths};
    }

    public int[] pathsWithMaxScore(List<String> board) {
        n = board.size();
        scoreMemo = new int[n][n];
        pathMemo = new int[n][n];

        for (int[] row : scoreMemo)
            Arrays.fill(row, -1);

        return solve(n - 1, n - 1, board);
    }
}
