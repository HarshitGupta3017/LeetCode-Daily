// Solution for Two Furthest Houses With Different Colors in CPP

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int totalHouses = colors.size();
        int maximumDistance = 0;

        // Traverse all houses
        for (int currentIndex = 0; currentIndex < totalHouses; currentIndex++) {

            // Case 1:
            // Compare with first house (index 0)
            if (colors[currentIndex] != colors[0]) {
                maximumDistance = max(maximumDistance, currentIndex); // distance = i - 0
            }

            // Case 2:
            // Compare with last house (index n-1)
            if (colors[currentIndex] != colors[totalHouses - 1]) {
                maximumDistance = max(maximumDistance, (totalHouses - 1 - currentIndex));
            }
        }

        return maximumDistance;
    }
};
