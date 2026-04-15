// Solution for Shortest Distance to Target String in a Circular Array in JAVA

class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        
        int totalWords = words.length;
        int minimumSteps = Integer.MAX_VALUE;

        // Traverse all positions to find occurrences of target
        for (int currentIndex = 0; currentIndex < totalWords; currentIndex++) {

            // Check if current word matches target
            if (words[currentIndex].equals(target)) {

                // Linear distance (direct movement)
                int linearDistance = Math.abs(currentIndex - startIndex);

                // Circular distance (wrap-around movement)
                int circularDistance = totalWords - linearDistance;

                // Choose the minimum of both paths
                int bestDistance = Math.min(linearDistance, circularDistance);

                // Update global minimum
                minimumSteps = Math.min(minimumSteps, bestDistance);
            }
        }

        // If target was never found, return -1
        return (minimumSteps == Integer.MAX_VALUE) ? -1 : minimumSteps;
    }
}
