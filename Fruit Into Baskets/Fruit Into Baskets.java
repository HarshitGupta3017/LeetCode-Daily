// Solution for Fruit Into Baskets in JAVA

class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> fruitCount = new HashMap<>();
        int windowStart = 0;
        int maxFruitsCollected = 0;

        for (int windowEnd = 0; windowEnd < fruits.length; windowEnd++) {
            fruitCount.put(fruits[windowEnd], fruitCount.getOrDefault(fruits[windowEnd], 0) + 1);

            while (fruitCount.size() > 2) {
                fruitCount.put(fruits[windowStart], fruitCount.get(fruits[windowStart]) - 1);
                if (fruitCount.get(fruits[windowStart]) == 0) {
                    fruitCount.remove(fruits[windowStart]);
                }
                windowStart++;
            }

            maxFruitsCollected = Math.max(maxFruitsCollected, windowEnd - windowStart + 1);
        }

        return maxFruitsCollected;
    }
}
