// Solution for Minimum Time Visiting All Points in CPP

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;

        // Traverse consecutive points in order
        for (int i = 0; i < points.size() - 1; i++) {

            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];

            // Distance to move in x and y directions
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);

            /*
                WHY this formula works:
                ----------------------
                - Diagonal moves reduce BOTH dx and dy by 1 in 1 second
                  → we should use as many diagonal moves as possible
                  → count = min(dx, dy)

                - After diagonals, one direction may still have distance left
                  → that leftover distance = abs(dx - dy)
                  → must be covered using straight moves

                Total time = diagonal moves + straight moves
                           = min(dx, dy) + abs(dx - dy)
                           = max(dx, dy)
            */
            totalTime += min(dx, dy) + abs(dx - dy);
        }

        return totalTime;
    }
};
