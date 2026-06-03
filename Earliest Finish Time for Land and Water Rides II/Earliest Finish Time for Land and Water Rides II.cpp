// Solution for Earliest Finish Time for Land and Water Rides II in CPP

class Solution {
public:

    // Finds the best finish time when we commit to doing all "first" rides before any "second" ride.
    // For each second ride j, we want the earliest possible finish: we pick whichever first ride
    // finishes the earliest, then board second ride j as soon as it opens (or right after landing).
    void solve(vector<int>& firstStart, vector<int>& firstDuration, vector<int>& secondStart, vector<int>& secondDuration, int& earliestFinish) {

        // Find the earliest time we can possibly finish any one first-category ride.
        // A ride started at its opening time gives the earliest finish: startTime + duration.
        // We never benefit from starting later, so opening time is always optimal for the first ride.
        int earliestFirstFinish = INT_MAX;
        for (int i = 0; i < firstStart.size(); i++) {
            earliestFirstFinish = min(earliestFirstFinish, firstStart[i] + firstDuration[i]);
        }

        // For each candidate second ride, compute the finish time if we pair it with
        // the best first ride found above.
        for (int j = 0; j < secondStart.size(); j++) {
            // We can board the second ride only after both conditions are met:
            // 1. We've finished the first ride (earliestFirstFinish).
            // 2. The second ride has actually opened (secondStart[j]).
            // max() captures whichever constraint is binding at this moment.
            int boardSecondAt = max(earliestFirstFinish, secondStart[j]);

            earliestFinish = min(earliestFinish, boardSecondAt + secondDuration[j]);
        }
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int result = INT_MAX;

        // Try both orderings: land first then water, and water first then land.
        // The tourist can do the rides in either order, so we check both and take the best.
        solve(landStartTime, landDuration, waterStartTime, waterDuration, result);
        solve(waterStartTime, waterDuration, landStartTime, landDuration, result);

        return result;
    }
};
