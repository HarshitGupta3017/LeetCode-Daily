// Solution for Painting a Grid With Three Different Colors in JAVA

class Solution {

    List<String> columnStates = new ArrayList<>();
    static final int MOD = 1000_000_007;

    private void generateColumnStates(String curr, char prevChar, int l, int m) {
        if (l == m) {
            columnStates.add(curr);
            return;
        }
        for (char currColor: new char[]{'R', 'G', 'B'}) {
            if (currColor == prevChar)
                continue;
            generateColumnStates(curr + currColor, currColor, l + 1, m);
        }
    }

    private int solve(int remainCols, int prevIdx, int m, int[][] dp) {
        if (remainCols == 0) {
            return 1;
        }
        if (dp[remainCols][prevIdx] != -1) {
            return dp[remainCols][prevIdx];
        }
        int ways = 0;
        String prevState = columnStates.get(prevIdx);
        for (int i = 0; i < columnStates.size(); i++) {
            if (i == prevIdx)
                continue;
            String currState = columnStates.get(i);
            boolean valid = true;
            for (int j = 0; j < m; j++) {
                if (prevState.charAt(j) == currState.charAt(j)) {
                    valid = false;
                }
            }
            if (valid) {
                ways = (ways + solve(remainCols - 1, i, m, dp)) % MOD;
            }
        }
        return dp[remainCols][prevIdx] = ways;
    }


    public int colorTheGrid(int m, int n) {
        generateColumnStates("", '#', 0, m);
        int totalStates = columnStates.size();
        int[][] dp = new int[n + 1][totalStates + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        int result = 0;
        for (int i = 0; i < columnStates.size(); i++) {
            result = (result + solve(n - 1, i, m, dp)) % MOD;
        }
        return result;
    }
}
