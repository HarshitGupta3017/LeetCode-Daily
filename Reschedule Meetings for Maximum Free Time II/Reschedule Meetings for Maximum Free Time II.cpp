// Solution for Reschedule Meetings for Maximum Free Time II in CPP

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        // Step 1: Compute the initial free gaps before, between, and after meetings
        vector<int> freeGaps;
        freeGaps.push_back(startTime[0]); // Free time before the first meeting

        for (int i = 1; i < n; i++) {
            freeGaps.push_back(startTime[i] - endTime[i - 1]); // Free time between meetings
        }

        freeGaps.push_back(eventTime - endTime[n - 1]); // Free time after the last meeting

        int m = freeGaps.size(); // Total number of free intervals (n + 1)

        // Step 2: Precompute max free time on the right side for quick lookups
        vector<int> maxRightFree(m, 0);
        for (int i = m - 2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i + 1], freeGaps[i + 1]);
        }

        // Step 3: Try removing/rescheduling each meeting one by one
        int maxFree = 0;
        int maxLeftFree = 0;

        for (int i = 1; i < m; i++) {
            // Duration of (i-1)th meeting
            int meetingDuration = endTime[i - 1] - startTime[i - 1];

            // Case 1: Move the meeting entirely into the largest free gap (left or right)
            if (meetingDuration <= max(maxLeftFree, maxRightFree[i])) {
                int combinedFree = freeGaps[i - 1] + meetingDuration + freeGaps[i];
                maxFree = max(maxFree, combinedFree);
            }

            // Case 2: Shift meeting slightly left or right but can't fully insert it elsewhere
            maxFree = max(maxFree, freeGaps[i - 1] + freeGaps[i]);

            // Update the max free time seen on the left
            maxLeftFree = max(maxLeftFree, freeGaps[i - 1]);
        }

        return maxFree;
    }
};
