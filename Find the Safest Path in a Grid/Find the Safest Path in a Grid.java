// Solution for Find the Safest Path in a Grid in JAVA

class Solution {
    private final int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // BFS from (0,0) to (n-1,n-1) visiting only cells whose distance
    // from the nearest thief is >= minSafeness.
    private boolean canReachWithSafeness(int[][] distFromThief, int minSafeness, int n) {
        if (distFromThief[0][0] < minSafeness) {
            return false;
        }

        boolean[][] visited = new boolean[n][n];
        Queue<int[]> queue = new LinkedList<>();

        queue.offer(new int[]{0, 0});
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int row = curr[0], col = curr[1];

            if (row == n - 1 && col == n - 1) {
                return true;
            }

            for (int[] dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) {
                    continue;
                }
                if (visited[newRow][newCol]) {
                    continue;
                }
                if (distFromThief[newRow][newCol] < minSafeness) {
                    continue;
                }

                visited[newRow][newCol] = true;
                queue.offer(new int[]{newRow, newCol});
            }
        }

        return false;
    }

    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();

        int[][] distFromThief = new int[n][n];
        boolean[][] visited = new boolean[n][n];

        for (int[] row : distFromThief) {
            Arrays.fill(row, -1);
        }

        Queue<int[]> queue = new LinkedList<>();

        // Multi-source BFS from all thieves.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid.get(i).get(j) == 1) {
                    queue.offer(new int[]{i, j});
                    visited[i][j] = true;
                    distFromThief[i][j] = 0;
                }
            }
        }

        int dist = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();

            while (size-- > 0) {
                int[] curr = queue.poll();
                int row = curr[0], col = curr[1];

                distFromThief[row][col] = dist;

                for (int[] dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) {
                        continue;
                    }
                    if (visited[newRow][newCol]) {
                        continue;
                    }

                    visited[newRow][newCol] = true;
                    queue.offer(new int[]{newRow, newCol});
                }
            }

            dist++;
        }

        int lo = 0, hi = 400, ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canReachWithSafeness(distFromThief, mid, n)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
}
