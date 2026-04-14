// Solution for Minimum Total Distance Traveled in JAVA

class Solution {

    private long solve(int robotIndex,
                       int positionIndex,
                       List<Integer> robot,
                       List<Integer> factoryPositions,
                       long[][] dp) {

        if (robotIndex >= robot.size())
            return 0;

        if (positionIndex >= factoryPositions.size())
            return (long) 1e18;

        if (dp[robotIndex][positionIndex] != -1)
            return dp[robotIndex][positionIndex];

        // Assign
        long assign =
                Math.abs(robot.get(robotIndex) - factoryPositions.get(positionIndex)) +
                solve(robotIndex + 1, positionIndex + 1,
                      robot, factoryPositions, dp);

        // Skip
        long skip =
                solve(robotIndex, positionIndex + 1,
                      robot, factoryPositions, dp);

        return dp[robotIndex][positionIndex] = Math.min(assign, skip);
    }

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {

        // Sort robots
        Collections.sort(robot);

        // Sort factories by position
        Arrays.sort(factory, (a, b) -> a[0] - b[0]);

        // Expand factory capacities
        List<Integer> factoryPositions = new ArrayList<>();

        for (int[] f : factory) {
            int position = f[0];
            int capacity = f[1];

            for (int i = 0; i < capacity; i++) {
                factoryPositions.add(position);
            }
        }

        int n = robot.size();
        int m = factoryPositions.size();

        long[][] dp = new long[n + 1][m + 1];
        for (long[] row : dp)
            Arrays.fill(row, -1);

        return solve(0, 0, robot, factoryPositions, dp);
    }
}
