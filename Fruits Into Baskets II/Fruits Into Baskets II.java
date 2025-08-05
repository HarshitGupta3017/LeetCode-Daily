// Solution for Fruits Into Baskets II in JAVA

class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int totalFruits = fruits.length;
        int totalBaskets = baskets.length;

        boolean[] isBasketUsed = new boolean[totalBaskets]; // Track used baskets
        int unplacedFruitCount = 0;

        for (int i = 0; i < totalFruits; i++) {
            boolean isPlaced = false;
            for (int j = 0; j < totalBaskets; j++) {
                if (!isBasketUsed[j] && baskets[j] >= fruits[i]) {
                    isBasketUsed[j] = true;
                    isPlaced = true;
                    break;
                }
            }
            if (!isPlaced) {
                unplacedFruitCount++;
            }
        }

        return unplacedFruitCount;
    }
}
