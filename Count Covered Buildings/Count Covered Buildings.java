// Solution for Count Covered Buildings in JAVA

class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {

        // Maps row (y) → {minX, maxX}
        Map<Integer, int[]> rowToMinMaxX = new HashMap<>();

        // Maps column (x) → {minY, maxY}
        Map<Integer, int[]> colToMinMaxY = new HashMap<>();

        // Step 1: Precompute boundaries
        for (int[] b : buildings) {
            int x = b[0];
            int y = b[1];

            rowToMinMaxX.putIfAbsent(y, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});
            colToMinMaxY.putIfAbsent(x, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});

            // Update row boundaries
            rowToMinMaxX.get(y)[0] = Math.min(rowToMinMaxX.get(y)[0], x);
            rowToMinMaxX.get(y)[1] = Math.max(rowToMinMaxX.get(y)[1], x);

            // Update column boundaries
            colToMinMaxY.get(x)[0] = Math.min(colToMinMaxY.get(x)[0], y);
            colToMinMaxY.get(x)[1] = Math.max(colToMinMaxY.get(x)[1], y);
        }

        // Step 2: Count covered buildings
        int covered = 0;

        for (int[] b : buildings) {
            int x = b[0];
            int y = b[1];

            int[] rowLimits = rowToMinMaxX.get(y); // {minX, maxX}
            int[] colLimits = colToMinMaxY.get(x); // {minY, maxY}

            boolean hasLeft = rowLimits[0] < x;
            boolean hasRight = x < rowLimits[1];
            boolean hasBelow = colLimits[0] < y;
            boolean hasAbove = y < colLimits[1];

            if (hasLeft && hasRight && hasBelow && hasAbove) {
                covered++;
            }
        }

        return covered;
    }
}
