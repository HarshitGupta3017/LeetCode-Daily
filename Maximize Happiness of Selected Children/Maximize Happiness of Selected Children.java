// Solution for Maximize Happiness of Selected Children in JAVA

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int n = happiness.length;

        // Sort happiness in descending order
        Integer[] happinessDesc = Arrays.stream(happiness).boxed().toArray(Integer[]::new);
        Arrays.sort(happinessDesc, Collections.reverseOrder());

        long totalHappiness = 0;

        // Select k children
        for (int turn = 0; turn < k; turn++) {
            // Happiness decreases by 1 for each previously selected child
            long currentHappiness = Math.max(happinessDesc[turn] - turn, 0);
            totalHappiness += currentHappiness;
        }

        return totalHappiness;
    }
}
