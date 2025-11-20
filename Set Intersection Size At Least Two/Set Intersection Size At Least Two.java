// Solution for Set Intersection Size At Least Two in JAVA

class Solution {
    public int intersectionSizeTwo(int[][] intervals) {

        // Sort by end ASC, and if end same, start DESC
        Arrays.sort(intervals, (a, b) -> {
            if (a[1] == b[1]) return b[0] - a[0];
            return a[1] - b[1];
        });

        int secondLast = intervals[0][1] - 1;
        int last = intervals[0][1];

        int selectedCount = 2; // already picked 2 points for the first interval

        for (int i = 1; i < intervals.length; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Case 1: interval already contains both points
            if (secondLast >= start) {
                continue;
            }
            // Case 2: interval contains only `last`
            else if (last >= start) {
                secondLast = last;
                last = end;
                selectedCount++;
            }
            // Case 3: contains none → add 2 new points
            else {
                secondLast = end - 1;
                last = end;
                selectedCount += 2;
            }
        }
        return selectedCount;
    }
}
