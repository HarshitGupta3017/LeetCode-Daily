// Solution for Two Best Non-Overlapping Events in JAVA

import java.util.*;

class Solution {

    // Recursive DP function
    // index        -> current event index
    // eventsTaken  -> number of events already attended (0, 1, or 2)
    // totalEvents  -> total number of events
    // dp[index][eventsTaken] -> memoized result
    private int dfs(int[][] events,
                    int index,
                    int eventsTaken,
                    int totalEvents,
                    int[][] dp) {

        // Base case:
        // If we've already taken 2 events OR no events left
        if (eventsTaken == 2 || index >= totalEvents) {
            return 0;
        }

        // Return memoized value if already computed
        if (dp[index][eventsTaken] != -1) {
            return dp[index][eventsTaken];
        }

        // ----------------------------------------------------
        // Option 1: Skip current event
        // ----------------------------------------------------
        int skipCurrent = dfs(events, index + 1, eventsTaken, totalEvents, dp);

        // ----------------------------------------------------
        // Option 2: Take current event
        // ----------------------------------------------------
        int nextIndex = findNextEvent(events, index, totalEvents);

        int takeCurrent =
            events[index][2] +
            dfs(events, nextIndex, eventsTaken + 1, totalEvents, dp);

        // Store and return the best choice
        return dp[index][eventsTaken] = Math.max(skipCurrent, takeCurrent);
    }

    // Binary search to find the next event whose start time
    // is >= current event's end time + 1
    private int findNextEvent(int[][] events, int index, int totalEvents) {

        int left = index + 1;
        int right = totalEvents - 1;
        int answer = totalEvents;

        int currentEndTime = events[index][1];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (events[mid][0] > currentEndTime) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    public int maxTwoEvents(int[][] events) {

        int totalEvents = events.length;

        // Sort events by start time
        Arrays.sort(events, (a, b) -> a[0] - b[0]);

        // dp[index][eventsTaken]
        int[][] dp = new int[totalEvents][3];
        for (int i = 0; i < totalEvents; i++) {
            Arrays.fill(dp[i], -1);
        }

        // Start recursion from index 0 with 0 events taken
        return dfs(events, 0, 0, totalEvents, dp);
    }
}
