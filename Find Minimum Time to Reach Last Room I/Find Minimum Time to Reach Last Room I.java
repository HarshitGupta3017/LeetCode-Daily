// Solution for Find Minimum Time to Reach Last Room I in JAVA

class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int m = moveTime.length;
        int n = moveTime[0].length;
        int[][] res = new int[m][n];
        for (int[] row : res) Arrays.fill(row, Integer.MAX_VALUE);
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, 0, 0});
        res[0][0] = 0;
        int[][] directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int currTime = curr[0], i = curr[1], j = curr[2];
            if (i == m - 1 && j == n - 1) return currTime;
            for (int[] dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    int waitTime = Math.max(moveTime[i_][j_] - currTime, 0);
                    int arrTime = waitTime + currTime + 1;
                    if (res[i_][j_] > arrTime) {
                        res[i_][j_] = arrTime;
                        pq.offer(new int[]{arrTime, i_, j_});
                    }
                }
            }
        }
        return -1;
    }
}
