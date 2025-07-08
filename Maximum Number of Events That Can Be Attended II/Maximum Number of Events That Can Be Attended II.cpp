// Solution for Maximum Number of Events That Can Be Attended II in CPP

class Solution {
public:

    // Recursive function to find the maximum value by attending up to k events starting from index `idx`
    int getMaxValue(vector<vector<int>>& events, int idx, int remainingEvents, int totalEvents, vector<vector<int>>& dp) {
        if (idx >= totalEvents || remainingEvents == 0) return 0;
        
        // Return cached result if already computed
        if (dp[idx][remainingEvents] != -1) {
            return dp[idx][remainingEvents];
        }

        // Option 1: Skip the current event
        int skip = getMaxValue(events, idx + 1, remainingEvents, totalEvents, dp);

        // Option 2: Take the current event
        int currentStart = events[idx][0];
        int currentEnd = events[idx][1];
        int currentValue = events[idx][2];

        // Find the next event that starts after current event's end day (strictly greater)
        int nextIndex = idx + 1;
        for (; nextIndex < totalEvents; nextIndex++) {
            if (events[nextIndex][0] > events[idx][1]) 
                break;
        }
        // vector<int> dummyEvent = {currentEnd, INT_MAX, INT_MAX}; // to use with upper_bound
        // int nextIndex = upper_bound(events.begin() + idx + 1, events.end(), dummyEvent) - events.begin();

        int take = currentValue + getMaxValue(events, nextIndex, remainingEvents - 1, totalEvents, dp);

        // Return the best option
        return dp[idx][remainingEvents] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by their start day
        sort(events.begin(), events.end());

        int totalEvents = events.size();

        // Step 2: Initialize memoization table with -1
        vector<vector<int>> dp(totalEvents + 1, vector<int>(k + 1, -1));

        // Start recursion from index 0 with full k events available
        return getMaxValue(events, 0, k, totalEvents, dp);
    }
};
