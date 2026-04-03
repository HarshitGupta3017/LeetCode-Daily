// Solution for Maximum Walls Destroyed by Robots in CPP

class Solution {
public:

    using P = pair<int, int>;

    /*
        Count how many walls lie in range [left, right]
        Using binary search since walls[] is sorted
    */
    int countWalls(vector<int>& walls, int left, int right) {

        // First wall >= left
        int leftIdx = lower_bound(walls.begin(), walls.end(), left) - walls.begin();

        // First wall > right
        int rightIdx = upper_bound(walls.begin(), walls.end(), right) - walls.begin();

        return rightIdx - leftIdx;
    }

    /*
        DP Function

        i → current robot index
        prevDir →
            0 = previous robot fired LEFT
            1 = previous robot fired RIGHT

        Why prevDir matters?
        → If previous robot fired RIGHT, its bullet already covered some area
          So current robot's LEFT range must be adjusted to avoid overlap
    */
    int dfs(vector<int>& walls,
            vector<P>& robots,      // {position, distance}
            vector<P>& validRange,  // effective [L, R] for each robot
            int i,
            int prevDir,
            vector<vector<int>>& dp) {

        // All robots processed
        if (i == robots.size()) return 0;

        if (dp[i][prevDir] != -1) return dp[i][prevDir];

        int robotPos = robots[i].first;

        /*
        ============================================================
        OPTION 1: FIRE LEFT
        ============================================================
        */

        int leftStart = validRange[i].first;

        /*
            IMPORTANT:
            If previous robot fired RIGHT,
            it may already cover part of this robot's LEFT side.

            So we shift leftStart to avoid double counting
        */
        if (prevDir == 1 && i > 0) {
            leftStart = max(leftStart, validRange[i - 1].second + 1);
        }

        int wallsDestroyedLeft =
            countWalls(walls, leftStart, robotPos) +
            dfs(walls, robots, validRange, i + 1, 0, dp);

        /*
        ============================================================
        OPTION 2: FIRE RIGHT
        ============================================================
        */

        int wallsDestroyedRight =
            countWalls(walls, robotPos, validRange[i].second) +
            dfs(walls, robots, validRange, i + 1, 1, dp);

        /*
            Choose best option
        */
        return dp[i][prevDir] = max(wallsDestroyedLeft, wallsDestroyedRight);
    }

    int maxWalls(vector<int>& robotsPos, vector<int>& distance, vector<int>& walls) {

        int n = robotsPos.size();

        /*
        ============================================================
        STEP 1: Combine robot position + distance
        ============================================================
        */
        vector<P> robots(n);
        for (int i = 0; i < n; i++) {
            robots[i] = {robotsPos[i], distance[i]};
        }

        /*
        ============================================================
        STEP 2: Sort robots & walls
        ============================================================
        */
        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());

        /*
        ============================================================
        STEP 3: Compute VALID RANGE for each robot
        ============================================================

        A robot cannot shoot THROUGH another robot.

        So its effective range is bounded by neighbors.
        */
        vector<P> validRange(n);

        for (int i = 0; i < n; i++) {

            int pos = robots[i].first;
            int dist = robots[i].second;

            // Can't cross previous robot
            int leftLimit = (i == 0) ? 1 : robots[i - 1].first + 1;

            // Can't cross next robot
            int rightLimit = (i == n - 1) ? 1e9 : robots[i + 1].first - 1;

            int L = max(leftLimit, pos - dist);
            int R = min(rightLimit, pos + dist);

            validRange[i] = {L, R};
        }

        /*
        ============================================================
        STEP 4: DP Initialization
        ============================================================
        */
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return dfs(walls, robots, validRange, 0, 0, dp);
    }
};
