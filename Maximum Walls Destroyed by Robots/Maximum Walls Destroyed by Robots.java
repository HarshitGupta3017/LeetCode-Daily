// Solution for Maximum Walls Destroyed by Robots in JAVA

class Solution {

    int countWalls(List<Integer> walls, int left, int right) {
        int l = Collections.binarySearch(walls, left);
        if (l < 0) l = -l - 1;

        int r = Collections.binarySearch(walls, right);
        if (r < 0) r = -r - 1;
        else r += 1;

        return r - l;
    }

    int dfs(List<Integer> walls, int[][] robots, int[][] range,
            int i, int prev, int[][] dp) {

        if (i == robots.length) return 0;
        if (dp[i][prev] != -1) return dp[i][prev];

        int pos = robots[i][0];

        int leftStart = range[i][0];
        if (prev == 1 && i > 0)
            leftStart = Math.max(leftStart, range[i - 1][1] + 1);

        int left = countWalls(walls, leftStart, pos) +
                   dfs(walls, robots, range, i + 1, 0, dp);

        int right = countWalls(walls, pos, range[i][1]) +
                    dfs(walls, robots, range, i + 1, 1, dp);

        return dp[i][prev] = Math.max(left, right);
    }

    public int maxWalls(int[] robotsPos, int[] dist, int[] wallsArr) {

        int n = robotsPos.length;

        int[][] robots = new int[n][2];
        for (int i = 0; i < n; i++) {
            robots[i][0] = robotsPos[i];
            robots[i][1] = dist[i];
        }

        Arrays.sort(robots, Comparator.comparingInt(a -> a[0]));
        Arrays.sort(wallsArr);

        List<Integer> walls = new ArrayList<>();
        for (int w : wallsArr) walls.add(w);

        int[][] range = new int[n][2];

        for (int i = 0; i < n; i++) {
            int pos = robots[i][0], d = robots[i][1];

            int L = Math.max(i == 0 ? 1 : robots[i - 1][0] + 1, pos - d);
            int R = Math.min(i == n - 1 ? (int)1e9 : robots[i + 1][0] - 1, pos + d);

            range[i][0] = L;
            range[i][1] = R;
        }

        int[][] dp = new int[n][2];
        for (int[] row : dp) Arrays.fill(row, -1);

        return dfs(walls, robots, range, 0, 0, dp);
    }
}
