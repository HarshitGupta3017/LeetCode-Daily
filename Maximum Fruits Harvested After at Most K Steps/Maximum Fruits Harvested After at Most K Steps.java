// Solution for Maximum Fruits Harvested After at Most K Steps in JAVA

class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int n = fruits.length;
        int[] fruitPositions = new int[n];
        int[] cumulativeFruits = new int[n];

        fruitPositions[0] = fruits[0][0];
        cumulativeFruits[0] = fruits[0][1];

        for (int i = 1; i < n; i++) {
            fruitPositions[i] = fruits[i][0];
            cumulativeFruits[i] = cumulativeFruits[i - 1] + fruits[i][1];
        }

        int maxCollected = 0;

        for (int detour = 0; detour <= k / 2; detour++) {
            // Case 1: Left first then right
            int leftLimit = startPos - detour;
            int rightLimit = startPos + (k - 2 * detour);

            int leftIdx = lowerBound(fruitPositions, leftLimit);
            int rightIdx = upperBound(fruitPositions, rightLimit) - 1;

            if (leftIdx <= rightIdx) {
                int total = cumulativeFruits[rightIdx] - (leftIdx > 0 ? cumulativeFruits[leftIdx - 1] : 0);
                maxCollected = Math.max(maxCollected, total);
            }

            // Case 2: Right first then left
            rightLimit = startPos + detour;
            leftLimit = startPos - (k - 2 * detour);

            leftIdx = lowerBound(fruitPositions, leftLimit);
            rightIdx = upperBound(fruitPositions, rightLimit) - 1;

            if (leftIdx <= rightIdx) {
                int total = cumulativeFruits[rightIdx] - (leftIdx > 0 ? cumulativeFruits[leftIdx - 1] : 0);
                maxCollected = Math.max(maxCollected, total);
            }
        }

        return maxCollected;
    }

    private int lowerBound(int[] arr, int target) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    private int upperBound(int[] arr, int target) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
}
