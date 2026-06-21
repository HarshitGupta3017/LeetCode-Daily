// Solution for Maximum Ice Cream Bars in CPP

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Find the price ceiling so we only allocate as many buckets as needed.
        int maxCost = *max_element(costs.begin(), costs.end());

        // freq[p] = number of ice cream bars that cost exactly p coins.
        // This replaces comparison-based sorting — we bucket each price in O(n).
        vector<int> freq(maxCost + 1, 0);
        for (int cost : costs)
            freq[cost]++;

        int count = 0;

        // Sweep prices from cheapest to most expensive.
        // Buying cheaper bars first maximises the number we can afford.
        for (int price = 1; price <= maxCost; price++) {
            if (freq[price] == 0) continue;

            // We can afford at most floor(coins / price) bars at this price,
            // but we're also limited by how many bars at this price exist.
            int canBuy = min(freq[price], coins / price);

            count  += canBuy;
            coins  -= canBuy * price;

            // No remaining budget can buy anything at this price or higher.
            if (coins < price) break;
        }

        return count;
    }
};
