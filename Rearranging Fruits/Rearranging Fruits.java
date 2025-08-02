// Solution for Rearranging Fruits in JAVA

class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        Map<Integer, Integer> countDiff = new HashMap<>();
        int minFruitCost = Integer.MAX_VALUE;

        for (int cost : basket1) {
            countDiff.put(cost, countDiff.getOrDefault(cost, 0) + 1);
            minFruitCost = Math.min(minFruitCost, cost);
        }

        for (int cost : basket2) {
            countDiff.put(cost, countDiff.getOrDefault(cost, 0) - 1);
            minFruitCost = Math.min(minFruitCost, cost);
        }

        List<Integer> extra = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : countDiff.entrySet()) {
            int fruit = entry.getKey(), diff = entry.getValue();
            if (diff % 2 != 0) return -1;
            for (int i = 0; i < Math.abs(diff) / 2; i++) {
                extra.add(fruit);
            }
        }

        Collections.sort(extra);
        long totalCost = 0;
        int swapsNeeded = extra.size() / 2;

        for (int i = 0; i < swapsNeeded; i++) {
            totalCost += Math.min(extra.get(i), 2 * minFruitCost);
        }

        return totalCost;
    }
}
