// Solution for Find the Number of Ways to Place People II in JAVA

class Solution {
    public int numberOfPairs(int[][] points) {
        int n = points.length;
        int result = 0;

        // Sort by x ascending, if x same then y descending
        Arrays.sort(points, (a, b) -> {
            if (a[0] == b[0]) {
                return b[1] - a[1];
            }
            return a[0] - b[0];
        });

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxY = Integer.MIN_VALUE; // track highest y seen so far for valid B

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                // Condition 1: A must be above B
                if (y2 > y1) continue;

                // Condition 2: ensure no blocking point in between
                if (y2 > maxY) {
                    result++;
                    maxY = y2;
                }
            }
        }
        return result;
    }
}
