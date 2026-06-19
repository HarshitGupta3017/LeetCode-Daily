// Solution for Find the Highest Altitude in JAVA

class Solution {
    public int largestAltitude(int[] gain) {

        int altitude = 0, maxAltitude = 0;

        for (int g : gain)
            maxAltitude = Math.max(maxAltitude, altitude += g);

        return maxAltitude;
    }
}
