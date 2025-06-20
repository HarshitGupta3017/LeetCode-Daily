// Solution for Maximum Manhattan Distance After K Changes in CPP

class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDistanceReached = 0;

        // Variables to track net movement in each direction
        int countNorth = 0, countSouth = 0;
        int countEast = 0, countWest = 0;

        for (int i = 0; i < s.size(); i++) {
            // Update direction counts based on current character
            if (s[i] == 'N') countNorth++;
            else if (s[i] == 'S') countSouth++;
            else if (s[i] == 'E') countEast++;
            else if (s[i] == 'W') countWest++;

            // Current Manhattan Distance from origin
            int currentDistance = abs(countNorth - countSouth) + abs(countEast - countWest);

            // Total steps taken so far
            int stepsSoFar = i + 1;

            // Steps that did not contribute to net displacement (cancelled moves)
            int wastedSteps = stepsSoFar - currentDistance;

            // We can convert at most k wasted moves (each flip helps reduce 2 wasted steps)
            int convertableWaste = min(2 * k, wastedSteps);

            // Final Manhattan distance after best k changes
            int possibleMaxDistance = currentDistance + convertableWaste;

            // Track the maximum across all positions
            maxDistanceReached = max(maxDistanceReached, possibleMaxDistance);
        }

        return maxDistanceReached;
    }
};
