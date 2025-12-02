// Solution for Count Number of Trapezoids I in CPP

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {

        const int MOD = 1e9 + 7;

        /*
            Key Insight:
            ------------
            A horizontal trapezoid needs **two horizontal pairs** of points.
            A “horizontal pair” = two points with the same y-coordinate.

            If a row (same y) has c points → it contributes:
                
                horizontalEdges = c * (c - 1) / 2   (choose any 2)

            If we have edges from different y-levels:
                For every earlier horizontalEdge A 
                and every new horizontalEdge B  
                we form a trapezoid using A + B.

            So we accumulate edges row-by-row:

                result += currentEdges * totalPreviousEdges
        */

        // Count how many points exist at each y-coordinate
        unordered_map<int, int> pointsAtY;
        for (const auto& pt : points) {
            pointsAtY[pt[1]]++;
        }

        long long totalTrapezoids = 0;
        long long accumulatedEdges = 0;   // Sum of horizontal edges from previous rows

        /*
            We iterate over all y-levels.
            Order does not matter since multiplication is symmetric.
        */
        for (const auto& [yCoord, countAtY] : pointsAtY) {

            // Number of horizontal line segments possible on this y-level
            long long horizontalEdges = 1LL * countAtY * (countAtY - 1) / 2;

            // Combine with previously accumulated horizontal edges
            totalTrapezoids = (totalTrapezoids +
                               (horizontalEdges % MOD) * (accumulatedEdges % MOD)) % MOD;

            // Add current edges to prefix total
            accumulatedEdges = (accumulatedEdges + horizontalEdges) % MOD;
        }

        return totalTrapezoids;
    }
};
