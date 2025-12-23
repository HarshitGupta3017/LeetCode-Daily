// Solution for Two Best Non-Overlapping Events in CPP

class Solution {
public:
    // Recursive DP function
    // index        -> current event index we are considering
    // eventsTaken  -> number of events already attended (0, 1, or 2)
    // totalEvents  -> total number of events
    // dp[index][eventsTaken] -> memoized max value from this state
    int dfs(vector<vector<int>>& events,
            int index,
            int eventsTaken,
            int totalEvents,
            vector<vector<int>>& dp) {

        // Base case:
        // If we've already taken 2 events OR no events left
        if (eventsTaken == 2 || index >= totalEvents) {
            return 0;
        }

        // Return memoized result if already computed
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
        // Find the next event whose start time is >= current end time + 1
        auto nextEventIt = upper_bound(
            events.begin() + index + 1,
            events.end(),
            events[index][1],
            [](int currentEndTime, const vector<int>& event) {
                return event[0] > currentEndTime;
            }
        );

        int nextIndex = (nextEventIt == events.end())
                        ? totalEvents
                        : nextEventIt - events.begin();

        int takeCurrent =
            events[index][2] +
            dfs(events, nextIndex, eventsTaken + 1, totalEvents, dp);

        // Store and return the best of both choices
        return dp[index][eventsTaken] = max(skipCurrent, takeCurrent);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int totalEvents = events.size();

        // Sort events by start time (required for binary search)
        sort(events.begin(), events.end());

        // dp[index][eventsTaken]
        vector<vector<int>> dp(totalEvents, vector<int>(3, -1));

        // Start recursion from index 0 with 0 events taken
        return dfs(events, 0, 0, totalEvents, dp);
    }
};
