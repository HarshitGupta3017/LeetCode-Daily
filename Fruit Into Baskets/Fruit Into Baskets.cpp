// Solution for Fruit Into Baskets in CPP

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int totalTrees = fruits.size();

        unordered_map<int, int> fruitCount; // Stores count of each fruit type in current window
        int windowStart = 0;                // Left end of the sliding window
        int maxFruitsCollected = 0;         // Stores the result

        // Expand the window from left to right
        for (int windowEnd = 0; windowEnd < totalTrees; windowEnd++) {
            fruitCount[fruits[windowEnd]]++; // Add current fruit to the basket

            // If we have more than 2 types of fruits, shrink the window from the left
            if (fruitCount.size() > 2) {
                fruitCount[fruits[windowStart]]--; // Remove the fruit at windowStart

                // If count becomes 0, remove the fruit type from the map
                if (fruitCount[fruits[windowStart]] == 0) {
                    fruitCount.erase(fruits[windowStart]);
                }

                windowStart++; // Move the left pointer ahead
            }

            // Update the maximum fruits collected in a valid window
            maxFruitsCollected = max(maxFruitsCollected, windowEnd - windowStart + 1);
        }

        return maxFruitsCollected;
    }
};
