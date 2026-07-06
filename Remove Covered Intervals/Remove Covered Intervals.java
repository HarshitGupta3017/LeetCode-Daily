// Solution for Remove Covered Intervals in JAVA

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        // Sort by left endpoint ascending; if equal, right endpoint descending.
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0]) {
                return b[1] - a[1];
            }
            return a[0] - b[0];
        });

        int maxRight = 0;
        int remaining = 0;

        for (int[] interval : intervals) {
            if (interval[1] > maxRight) {
                maxRight = interval[1];
                remaining++;
            }
        }

        return remaining;
    }
}
