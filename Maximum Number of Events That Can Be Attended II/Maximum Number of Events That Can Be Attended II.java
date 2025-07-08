// Solution for Maximum Number of Events That Can Be Attended II in JAVA

class Solution {
    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, Comparator.comparingInt(a -> a[0]));
        int n = events.length;
        int[][] dp = new int[n + 1][k + 1];
        for (int[] row : dp) Arrays.fill(row, -1);
        return getMax(events, 0, k, dp);
    }

    private int getMax(int[][] events, int idx, int k, int[][] dp) {
        if (idx >= events.length || k == 0) return 0;
        if (dp[idx][k] != -1) return dp[idx][k];

        int skip = getMax(events, idx + 1, k, dp);

        int nextIdx = idx + 1;
        while (nextIdx < events.length && events[nextIdx][0] <= events[idx][1]) {
            nextIdx++;
        }

        int take = events[idx][2] + getMax(events, nextIdx, k - 1, dp);
        return dp[idx][k] = Math.max(skip, take);
    }
}
