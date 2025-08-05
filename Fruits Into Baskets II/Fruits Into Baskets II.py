# Solution for Fruits Into Baskets II in PY

class Solution:
    def numOfUnplacedFruits(self, fruits, baskets):
        totalFruits = len(fruits)
        totalBaskets = len(baskets)

        isBasketUsed = [False] * totalBaskets  # Track used baskets
        unplacedFruitCount = 0

        for i in range(totalFruits):
            isPlaced = False
            for j in range(totalBaskets):
                if not isBasketUsed[j] and baskets[j] >= fruits[i]:
                    isBasketUsed[j] = True
                    isPlaced = True
                    break
            if not isPlaced:
                unplacedFruitCount += 1

        return unplacedFruitCount
