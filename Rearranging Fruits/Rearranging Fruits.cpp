// Solution for Rearranging Fruits in CPP

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> fruitCountDifference; // Stores the net count difference of each fruit between the two baskets
        int smallestFruitCost = INT_MAX; // Tracks the smallest cost among all fruits, used for minimizing swap cost

        // Step 1: Count how many of each fruit we have in basket1 and basket2
        for (const int& fruitCost : basket1) {
            fruitCountDifference[fruitCost]++;
            smallestFruitCost = min(smallestFruitCost, fruitCost); // update the smallest fruit cost seen
        }

        for (const int& fruitCost : basket2) {
            fruitCountDifference[fruitCost]--;
            smallestFruitCost = min(smallestFruitCost, fruitCost); // update the smallest fruit cost seen
        }

        // Step 2: Collect fruits that are extra in one of the baskets
        vector<int> extraFruitsToSwap; // Stores the fruit costs that are unbalanced and need to be swapped

        for (const auto& [fruitCost, countDifference] : fruitCountDifference) {
            // If a fruit appears equally in both baskets, skip
            if (countDifference == 0) continue;

            // If the count difference is odd, it's impossible to balance
            if (countDifference % 2 != 0) return -1;

            // Add half the difference (absolute) since one swap fixes two fruits
            for (int i = 0; i < abs(countDifference) / 2; i++) {
                extraFruitsToSwap.push_back(fruitCost);
            }
        }

        // Step 3: Sort the half of unmatched fruits (we'll only swap half of them)
        // We only need to process the smaller half because each swap uses 2 fruits
        // sort(extraFruitsToSwap.begin(), extraFruitsToSwap.end());
        nth_element(begin(extraFruitsToSwap), begin(extraFruitsToSwap) + extraFruitsToSwap.size()/2, end(extraFruitsToSwap));

        long long totalSwapCost = 0;
        int numberOfSwaps = extraFruitsToSwap.size() / 2;

        // Step 4: For each needed swap, choose the minimum cost option:
        // either swap this unmatched fruit directly, or perform a double swap with the globally cheapest fruit
        for (int i = 0; i < numberOfSwaps; i++) {
            int currentFruitCost = extraFruitsToSwap[i];

            // Cost of direct swap vs using two smallest fruits (cheapest workaround)
            int bestSwapCost = min(currentFruitCost, 2 * smallestFruitCost);

            totalSwapCost += bestSwapCost;
        }

        return totalSwapCost;
    }
};
