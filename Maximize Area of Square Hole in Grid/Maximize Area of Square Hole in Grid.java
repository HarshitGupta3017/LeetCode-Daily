// Solution for Maximize Area of Square Hole in Grid in JAVA

class Solution {

    /*
        Finds the maximum number of consecutive removable bars.
        Example: [2,3,4] → 3 consecutive bars
    */
    private int maxConsecutiveBars(int[] bars) {
        if (bars.length == 0) return 0;

        int maxCount = 1;
        int currentCount = 1;

        for (int i = 1; i < bars.length; i++) {
            if (bars[i] == bars[i - 1] + 1) {
                currentCount++;
            } else {
                currentCount = 1;
            }
            maxCount = Math.max(maxCount, currentCount);
        }
        return maxCount;
    }

    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {

        // Sort bars to detect consecutive removals
        Arrays.sort(hBars);
        Arrays.sort(vBars);

        int maxHorizontal = maxConsecutiveBars(hBars);
        int maxVertical = maxConsecutiveBars(vBars);

        /*
            Removing k consecutive bars creates (k + 1) free cells
            Square side = min(horizontalCells, verticalCells)
        */
        int squareSide = Math.min(maxHorizontal, maxVertical) + 1;

        return squareSide * squareSide;
    }
}
