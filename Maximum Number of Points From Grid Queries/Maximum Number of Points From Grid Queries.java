// Solution for Maximum Number of Points From Grid Queries in JAVA

class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length, n = grid[0].length;
        int q = queries.length;
        int[] res = new int[q];
        List<int[]> sortedQ = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            sortedQ.add(new int[]{queries[i], i});
        }
        sortedQ.sort(Comparator.comparingInt(a -> a[0]));
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        PriorityQueue<int[]> minH = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        boolean[][] vis = new boolean[m][n];
        int points = 0;
        minH.add(new int[]{grid[0][0], 0, 0});
        vis[0][0] = true;
        for (int k = 0; k < q; k++) {
            int val = sortedQ.get(k)[0];
            int idx = sortedQ.get(k)[1];
            while (!minH.isEmpty() && minH.peek()[0] < val) {
                int i = minH.peek()[1];
                int j = minH.peek()[2];
                minH.poll();
                points++;
                for (int[] dir: directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !vis[i_][j_]) {
                        minH.add(new int[]{grid[i_][j_], i_, j_});
                        vis[i_][j_] = true;
                    }
                }
            }
            res[idx] = points;
        }
        return res;
    }
}
