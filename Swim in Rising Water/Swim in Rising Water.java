// Solution for Swim in Rising Water in JAVA

class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;

        // Min-heap (priority queue) storing {elevation, row, col}
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        boolean[][] visited = new boolean[n][n];
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Start from top-left corner
        minHeap.offer(new int[]{grid[0][0], 0, 0});
        visited[0][0] = true;

        int minTime = 0;

        // Dijkstra-like BFS
        while (!minHeap.isEmpty()) {
            int[] cell = minHeap.poll();
            int currElevation = cell[0];
            int row = cell[1];
            int col = cell[2];

            minTime = Math.max(minTime, currElevation);

            // If reached bottom-right
            if (row == n - 1 && col == n - 1)
                return minTime;

            // Explore neighbors
            for (int[] dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    minHeap.offer(new int[]{grid[newRow][newCol], newRow, newCol});
                }
            }
        }

        return -1; // Should never reach here
    }
}
