// Solution for Count Number of Trapezoids I in JAVA

class Solution {
    public int countTrapezoids(int[][] points) {

        final long MOD = 1_000_000_007L;

        // Count points at each y-coordinate
        Map<Integer, Integer> pointsAtY = new HashMap<>();
        for (int[] pt : points) {
            pointsAtY.put(pt[1], pointsAtY.getOrDefault(pt[1], 0) + 1);
        }

        long totalTrapezoids = 0;
        long accumulatedEdges = 0;

        // Iterate through all y-levels (order doesn't matter)
        for (int countAtY : pointsAtY.values()) {

            long horizontalEdges = (long) countAtY * (countAtY - 1) / 2;

            totalTrapezoids = (totalTrapezoids +
                    (horizontalEdges % MOD) * (accumulatedEdges % MOD)) % MOD;

            accumulatedEdges = (accumulatedEdges + horizontalEdges) % MOD;
        }

        return (int) totalTrapezoids;
    }
}
