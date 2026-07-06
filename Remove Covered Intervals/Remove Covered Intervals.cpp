// Solution for Remove Covered Intervals in CPP

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort by left endpoint ascending; break ties by right endpoint descending.
        // Descending right endpoint on ties ensures that if two intervals share
        // the same left boundary, the wider one comes first — so the narrower one
        // is immediately recognised as covered and skipped.
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        // We only need to track the maximum right endpoint seen so far.
        // Since intervals are sorted by left endpoint, any new interval with
        // a right endpoint <= maxRight is fully covered by a previous interval.
        int maxRight = 0;
        int remaining = 0;

        for (const auto& interval : intervals) {
            if (interval[1] > maxRight) {
                // This interval extends beyond everything seen so far —
                // it cannot be covered by any previous interval.
                maxRight = interval[1];
                remaining++;
            }
            // Otherwise interval[1] <= maxRight, meaning a previously seen
            // interval already covers this one entirely — skip it.
        }

        return remaining;
    }
};
