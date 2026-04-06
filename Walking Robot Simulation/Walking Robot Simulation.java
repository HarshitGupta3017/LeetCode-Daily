// Solution for Walking Robot Simulation in JAVA

class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {

        // STEP 1: Store obstacles
        Set<String> obstacleSet = new HashSet<>();
        for (int[] obs : obstacles) {
            String key = obs[0] + "_" + obs[1];
            obstacleSet.add(key);
        }

        // STEP 2: Initialize
        int x = 0, y = 0;
        int maxDistanceSquared = 0;

        // Facing NORTH
        int dx = 0, dy = 1;

        // STEP 3: Process commands
        for (int command : commands) {

            // Turn Left
            if (command == -2) {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }

            // Turn Right
            else if (command == -1) {
                int temp = dx;
                dx = dy;
                dy = -temp;
            }

            // Move Forward
            else {
                while (command-- > 0) {

                    int nextX = x + dx;
                    int nextY = y + dy;

                    String key = nextX + "_" + nextY;

                    // Stop if obstacle
                    if (obstacleSet.contains(key)) break;

                    x = nextX;
                    y = nextY;
                }
            }

            // Update max distance
            maxDistanceSquared = Math.max(maxDistanceSquared, x * x + y * y);
        }

        return maxDistanceSquared;
    }
}
