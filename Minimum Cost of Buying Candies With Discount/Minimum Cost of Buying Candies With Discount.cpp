// Solution for Minimum Cost of Buying Candies With Discount in CPP

class Solution {
public:
   int minimumCost(vector<int>& cost) {
       // Sort in descending order so that the most expensive candies come first.
       // This ensures that whenever we get a free candy (every 3rd one),
       // it is the cheapest of the current group of three — maximizing savings.
       sort(rbegin(cost), rend(cost));

       int totalCost = 0;

       for (int i = 0; i < cost.size(); i++) {
           // Candies at positions 0,1 | 3,4 | 6,7 ... are the paid ones (two per group).
           // The candy at position 2, 5, 8 ... (every 3rd, 0-indexed) is the free one.
           // Skipping it means we never add its cost, simulating getting it for free.
           if (i % 3 != 2) {
               totalCost += cost[i];
           }
       }

       return totalCost;
   }
};
