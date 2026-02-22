// Solution for Binary Gap in JAVA

class Solution {
    public int binaryGap(int n) {

        int prevPosition = -1;
        int maxDistance = 0;

        // Check all 32 bit positions
        for (int currentPosition = 0; currentPosition < 32; currentPosition++) {

            // Check if current bit is 1
            if (((n >> currentPosition) & 1) == 1) {

                if (prevPosition != -1) {
                    int distance = currentPosition - prevPosition;
                    maxDistance = Math.max(maxDistance, distance);
                }

                prevPosition = currentPosition;
            }
        }

        return maxDistance;
    }
}
