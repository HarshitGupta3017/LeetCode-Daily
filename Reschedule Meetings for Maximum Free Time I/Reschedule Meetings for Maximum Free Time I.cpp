// Solution for Reschedule Meetings for Maximum Free Time I in CPP

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        // Step 1: Calculate all free time gaps
        vector<int> freeGaps;

        // Initial free time before first meeting
        freeGaps.push_back(startTime[0]);

        // Free time between consecutive meetings
        for (int i = 1; i < n; i++) {
            freeGaps.push_back(startTime[i] - endTime[i - 1]);
        }

        // Free time after the last meeting till event ends
        freeGaps.push_back(eventTime - endTime[n - 1]);

        // Step 2: Use sliding window to find max sum of any (k + 1) free gaps
        int maxFree = 0;
        int currSum = 0;
        int left = 0;

        for (int right = 0; right < freeGaps.size(); right++) {
            currSum += freeGaps[right];

            // Maintain window size of (k + 1) gaps
            while (right - left + 1 > k + 1) {
                currSum -= freeGaps[left];
                left++;
            }

            // Update max free time
            maxFree = max(maxFree, currSum);
        }

        return maxFree;
    }
};
