// Solution for Maximum Fruits Harvested After at Most K Steps in CPP

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        // Separate arrays for positions and prefix sums of fruit amounts
        vector<int> fruitPositions(n);   // Stores positions of fruits
        vector<int> cumulativeFruits(n); // Prefix sum array of fruit amounts

        // Fill the arrays
        for (int i = 0; i < n; i++) {
            fruitPositions[i] = fruits[i][0];
            cumulativeFruits[i] = fruits[i][1] + (i > 0 ? cumulativeFruits[i - 1] : 0);
        }

        int maxCollected = 0;

        // Try all distances 'd' such that 2*d <= k
        for (int detour = 0; detour <= k / 2; detour++) {

            // -------------------------
            // Case 1: Move left first, then right
            // -------------------------
            int leftLimit = startPos - detour;
            int rightLimit = startPos + (k - 2 * detour);  // Remaining distance after detouring left and coming back

            // Find range of fruits within [leftLimit, rightLimit]
            int leftIdx = lower_bound(fruitPositions.begin(), fruitPositions.end(), leftLimit) - fruitPositions.begin();
            int rightIdx = upper_bound(fruitPositions.begin(), fruitPositions.end(), rightLimit) - fruitPositions.begin() - 1;

            if (leftIdx <= rightIdx) {
                int totalFruits = cumulativeFruits[rightIdx] - (leftIdx > 0 ? cumulativeFruits[leftIdx - 1] : 0);
                maxCollected = max(maxCollected, totalFruits);
            }

            // -------------------------
            // Case 2: Move right first, then left
            // -------------------------
            rightLimit = startPos + detour;
            leftLimit = startPos - (k - 2 * detour); // Remaining distance after detouring right and coming back

            leftIdx = lower_bound(fruitPositions.begin(), fruitPositions.end(), leftLimit) - fruitPositions.begin();
            rightIdx = upper_bound(fruitPositions.begin(), fruitPositions.end(), rightLimit) - fruitPositions.begin() - 1;

            if (leftIdx <= rightIdx) {
                int totalFruits = cumulativeFruits[rightIdx] - (leftIdx > 0 ? cumulativeFruits[leftIdx - 1] : 0);
                maxCollected = max(maxCollected, totalFruits);
            }
        }

        return maxCollected;
    }
};
