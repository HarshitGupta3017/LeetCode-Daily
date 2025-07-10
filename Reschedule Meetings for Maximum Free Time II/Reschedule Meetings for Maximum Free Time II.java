// Solution for Reschedule Meetings for Maximum Free Time II in JAVA

class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int[] freeGaps = new int[n + 1];
        freeGaps[0] = startTime[0];

        for (int i = 1; i < n; i++) {
            freeGaps[i] = startTime[i] - endTime[i - 1];
        }

        freeGaps[n] = eventTime - endTime[n - 1];
        int m = freeGaps.length;

        int[] maxRightFree = new int[m];
        for (int i = m - 2; i >= 0; i--) {
            maxRightFree[i] = Math.max(maxRightFree[i + 1], freeGaps[i + 1]);
        }

        int maxFree = 0;
        int maxLeftFree = 0;

        for (int i = 1; i < m; i++) {
            int meetingDuration = endTime[i - 1] - startTime[i - 1];

            if (meetingDuration <= Math.max(maxLeftFree, maxRightFree[i])) {
                int combinedFree = freeGaps[i - 1] + meetingDuration + freeGaps[i];
                maxFree = Math.max(maxFree, combinedFree);
            }

            maxFree = Math.max(maxFree, freeGaps[i - 1] + freeGaps[i]);
            maxLeftFree = Math.max(maxLeftFree, freeGaps[i - 1]);
        }

        return maxFree;
    }
}
