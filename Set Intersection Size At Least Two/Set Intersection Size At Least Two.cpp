// Solution for Set Intersection Size At Least Two in CPP

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // Sort intervals by:
        // 1️⃣ Increasing end point
        // 2️⃣ If same end, decreasing start (to prioritize tighter intervals)
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] == b[1]) 
                return a[0] > b[0];
            return a[1] < b[1];
        });

        // We maintain two chosen points:
        // ls → second last chosen number
        // l  → last chosen number
        int secondLast = intervals[0][1] - 1;
        int last = intervals[0][1];

        // We already selected 2 points for the first interval
        int selectedCount = 2;

        // Process remaining intervals
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end   = interval[1];

            // Case 1: This interval already contains both chosen points
            if (secondLast >= start) {
                continue;
            }

            // Case 2: It contains only the last chosen point → add one more point
            else if (last >= start) {
                secondLast = last;
                last = end;
                selectedCount++;
            }

            // Case 3: Contains none → need to add 2 new points
            else {
                secondLast = end - 1;
                last = end;
                selectedCount += 2;
            }
        }

        return selectedCount;
    }
};
