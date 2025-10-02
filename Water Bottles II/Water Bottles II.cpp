// Solution for Water Bottles II in CPP

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrank = 0;  // Total number of bottles drunk

        // While we still have enough bottles to perform an exchange
        while (numBottles >= numExchange) {
            
            // Drink exactly 'numExchange' bottles
            totalDrank += numExchange;

            // After drinking, those bottles become empty, so subtract from full
            numBottles -= numExchange;

            // Exchange the empty bottles for 1 new full bottle
            numBottles += 1;

            // Increase the exchange cost by 1 (it becomes harder each time)
            numExchange++;
        }

        // Drink the remaining bottles that can’t be exchanged anymore
        return totalDrank + numBottles;
    }
};
