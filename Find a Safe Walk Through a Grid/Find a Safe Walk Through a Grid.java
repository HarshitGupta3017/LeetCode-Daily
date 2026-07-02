// Solution for Find a Safe Walk Through a Grid in JAVA

class Solution {
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m = grid.size();
        int n = grid.get(0).size();

        int[][] visited = new int[m][n];

        Queue<int[]> queue = new LinkedList<>();

        int startHealth = health - grid.get(0).get(0);
        if (startHealth <= 0) {
            return false;
        }

        queue.offer(new int[]{0, 0, startHealth});
        visited[0][0] = startHealth;

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int r = curr[0];
            int c = curr[1];
            int h = curr[2];

            if (r == m - 1 && c == n - 1) {
                return true;
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                int nh = h - grid.get(nr).get(nc);

                if (nh <= 0) {
                    continue;
                }

                if (visited[nr][nc] >= nh) {
                    continue;
                }

                visited[nr][nc] = nh;
                queue.offer(new int[]{nr, nc, nh});
            }
        }

        return false;
    }
}
