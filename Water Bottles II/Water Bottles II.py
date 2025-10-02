# Solution for Water Bottles II in PY

class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        totalDrank = 0

        while (numBottles >= numExchange) :
            
            totalDrank += numExchange

            numBottles -= numExchange

            numBottles += 1

            numExchange += 1

        return totalDrank + numBottles
