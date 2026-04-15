// Solution for Shortest Distance to Target String in a Circular Array in CPP

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        int totalWords = words.size();
        int minimumSteps = INT_MAX;

        // Traverse all positions to find occurrences of target
        for (int currentIndex = 0; currentIndex < totalWords; currentIndex++) {

            // Check if current word matches target
            if (words[currentIndex] == target) {

                // Linear distance (direct movement)
                int linearDistance = abs(currentIndex - startIndex);

                // Circular distance (wrap-around movement)
                int circularDistance = totalWords - linearDistance;

                // Choose the minimum of both paths
                int bestDistance = min(linearDistance, circularDistance);

                // Update global minimum
                minimumSteps = min(minimumSteps, bestDistance);
            }
        }

        // If target was never found, return -1
        return (minimumSteps == INT_MAX) ? -1 : minimumSteps;
    }
};
