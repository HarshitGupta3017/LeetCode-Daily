// Solution for Maximum Manhattan Distance After K Changes in JAVA

class Solution {
    public int maxDistance(String s, int k) {
        int maxDistanceReached = 0;
        int countNorth = 0, countSouth = 0;
        int countEast = 0, countWest = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == 'N') countNorth++;
            else if (ch == 'S') countSouth++;
            else if (ch == 'E') countEast++;
            else if (ch == 'W') countWest++;

            int currentDistance = Math.abs(countNorth - countSouth) + Math.abs(countEast - countWest);
            int stepsSoFar = i + 1;
            int wastedSteps = stepsSoFar - currentDistance;
            int convertibleWaste = Math.min(2 * k, wastedSteps);
            int possibleMaxDistance = currentDistance + convertibleWaste;

            maxDistanceReached = Math.max(maxDistanceReached, possibleMaxDistance);
        }

        return maxDistanceReached;
    }
}
