// Solution for Fruits Into Baskets II in CPP

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int totalFruits = fruits.size();     // Total number of fruit types
        int totalBaskets = baskets.size();   // Total number of baskets

        vector<bool> isBasketUsed(totalBaskets, false);  // Track whether a basket is already used

        int unplacedFruitCount = 0;          // Counter for fruits that could not be placed

        // Try placing each fruit in the first available basket that can hold it
        for (int i = 0; i < totalFruits; i++) {
            bool isPlaced = false;

            for (int j = 0; j < totalBaskets; j++) {
                // If the basket is unused and can hold the current fruit quantity
                if (!isBasketUsed[j] && baskets[j] >= fruits[i]) {
                    isBasketUsed[j] = true;  // Mark the basket as used
                    isPlaced = true;
                    break;                   // Move to next fruit
                }
            }

            // If no suitable basket found for the current fruit
            if (!isPlaced) {
                unplacedFruitCount++;
            }
        }

        return unplacedFruitCount;
    }
};
