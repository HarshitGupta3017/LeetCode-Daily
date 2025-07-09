// Solution for Reschedule Meetings for Maximum Free Time I in JAVA

class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int[] freeGaps = new int[n + 1];

        // Initial free time before first meeting
        freeGaps[0] = startTime[0];

        // Free time between consecutive meetings
        for (int i = 1; i < n; i++) {
            freeGaps[i] = startTime[i] - endTime[i - 1];
        }

        // Free time after last meeting
        freeGaps[n] = eventTime - endTime[n - 1];

        int maxFree = 0;
        int currSum = 0;
        int left = 0;

        for (int right = 0; right < freeGaps.length; right++) {
            currSum += freeGaps[right];

            while (right - left + 1 > k + 1) {
                currSum -= freeGaps[left];
                left++;
            }

            maxFree = Math.max(maxFree, currSum);
        }

        return maxFree;
    }
}
