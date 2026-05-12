// Solution for Minimum Initial Energy to Finish Tasks in JAVA

class Solution {
    public int minimumEffort(int[][] tasks) {

        // Sort by (minimum - actual) in descending order
        Arrays.sort(tasks, (a, b) ->
                (b[1] - b[0]) - (a[1] - a[0]));

        int minStartingEnergy = 0;
        int energyConsumed = 0;

        for (int[] task : tasks) {

            int actualCost = task[0];
            int minimumToStart = task[1];

            minStartingEnergy = Math.max(
                    minStartingEnergy,
                    energyConsumed + minimumToStart
            );

            energyConsumed += actualCost;
        }

        return minStartingEnergy;
    }
}
