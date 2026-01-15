// Solution for Maximize Area of Square Hole in Grid in CPP

class Solution {
public:
    /*
        Finds the maximum number of consecutive removable bars.
        Example: [2,3,4] → 3 consecutive bars
    */
    int maxConsecutiveBars(vector<int>& bars) {
        if (bars.empty()) return 0;

        int maxCount = 1;
        int currentCount = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                currentCount++;
            } else {
                currentCount = 1;
            }
            maxCount = max(maxCount, currentCount);
        }
        return maxCount;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        // Sort bars to detect consecutive removals
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxHorizontal = maxConsecutiveBars(hBars);
        int maxVertical = maxConsecutiveBars(vBars);

        /*
            Removing k consecutive bars creates (k + 1) free cells
            Square side = min(horizontalCells, verticalCells)
        */
        int squareSide = min(maxHorizontal, maxVertical) + 1;

        return squareSide * squareSide;
    }
};
