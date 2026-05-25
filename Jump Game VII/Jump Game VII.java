// Solution for Jump Game VII in JAVA

class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {

        int totalLength = s.length();

        // reachable[i] = true means index i can be reached
        boolean[] reachable = new boolean[totalLength];

        // Starting index is always reachable
        reachable[0] = true;

        // Stores how many reachable indices
        // currently exist inside the valid jump window
        int reachableCountInsideWindow = 0;

        for (int currentIndex = 1; currentIndex < totalLength; currentIndex++) {

            // Add the new index entering the valid jump window
            if (currentIndex - minJump >= 0) {

                if (reachable[currentIndex - minJump]) {
                    reachableCountInsideWindow++;
                }
            }

            // Remove the index leaving the valid jump window
            if (currentIndex - maxJump - 1 >= 0) {

                if (reachable[currentIndex - maxJump - 1]) {
                    reachableCountInsideWindow--;
                }
            }

            // Current index becomes reachable if:
            // 1. There is at least one reachable index
            //    inside the allowed jump range
            // 2. Current position contains '0'
            if (reachableCountInsideWindow > 0 && s.charAt(currentIndex) == '0') {

                reachable[currentIndex] = true;
            }
        }

        // Return whether last index is reachable
        return reachable[totalLength - 1];
    }
}
