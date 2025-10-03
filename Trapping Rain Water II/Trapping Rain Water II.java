// Solution for Trapping Rain Water II in JAVA

class Solution {
    public int trapRainWater(int[][] heightMap) {
        int rows = heightMap.length;
        int cols = heightMap[0].length;

        boolean[][] visited = new boolean[rows][cols];

        // Min-heap storing {height, row, col}
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]   // compare by height
        );

        // Step 1: Add boundary cells (left & right columns)
        for (int r = 0; r < rows; r++) {
            for (int c : new int[]{0, cols - 1}) {
                minHeap.add(new int[]{heightMap[r][c], r, c});
                visited[r][c] = true;
            }
        }

        // Step 2: Add boundary cells (top & bottom rows)
        for (int c = 0; c < cols; c++) {
            for (int r : new int[]{0, rows - 1}) {
                minHeap.add(new int[]{heightMap[r][c], r, c});
                visited[r][c] = true;
            }
        }

        int trappedWater = 0;
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Step 3: Process cells in increasing order of height
        while (!minHeap.isEmpty()) {
            int[] cur = minHeap.poll();
            int height = cur[0], row = cur[1], col = cur[2];

            // Step 4: Explore neighbors
            for (int[] dir : directions) {
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                    trappedWater += Math.max(0, height - heightMap[nr][nc]);

                    // Push neighbor with effective boundary height
                    minHeap.add(new int[]{Math.max(height, heightMap[nr][nc]), nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        return trappedWater;
    }
}
