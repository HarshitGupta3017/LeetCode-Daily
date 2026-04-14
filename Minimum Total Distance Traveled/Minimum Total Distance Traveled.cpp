// Solution for Minimum Total Distance Traveled in CPP

class Solution {
public:

    // Recursive DP:
    // i -> current robot index
    // j -> current position index (expanded factory positions)
    // Returns minimum distance to assign robots[i...end]
    long long solve(int robotIndex,
                    int positionIndex,
                    vector<int>& robotPositions,
                    vector<int>& factoryPositions,
                    vector<vector<long long>>& dp) {

        // Base Case 1: All robots are assigned
        if (robotIndex >= robotPositions.size())
            return 0;

        // Base Case 2: No more factory slots available
        if (positionIndex >= factoryPositions.size())
            return 1e18; // Large value (invalid assignment)

        // Memoization check
        if (dp[robotIndex][positionIndex] != -1)
            return dp[robotIndex][positionIndex];

        // -------------------------------
        // Choice 1: Assign current robot to current factory slot
        // -------------------------------
        long long assignCurrent =
            abs(robotPositions[robotIndex] - factoryPositions[positionIndex]) +
            solve(robotIndex + 1,
                  positionIndex + 1,
                  robotPositions,
                  factoryPositions,
                  dp);

        // -------------------------------
        // Choice 2: Skip current factory slot
        // -------------------------------
        long long skipCurrent =
            solve(robotIndex,
                  positionIndex + 1,
                  robotPositions,
                  factoryPositions,
                  dp);

        // Store and return the minimum cost
        return dp[robotIndex][positionIndex] =
            min(assignCurrent, skipCurrent);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        // Step 1: Sort robots and factories (critical for greedy alignment)
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Step 2: Expand factory capacities into individual positions
        // Example: [pos=5, limit=3] → [5, 5, 5]
        vector<int> factoryPositions;

        for (auto& factoryUnit : factory) {
            int position = factoryUnit[0];
            int capacity = factoryUnit[1];

            for (int count = 0; count < capacity; count++) {
                factoryPositions.push_back(position);
            }
        }

        int totalRobots = robot.size();
        int totalSlots = factoryPositions.size();

        // DP table initialization
        vector<vector<long long>> dp(
            totalRobots + 1,
            vector<long long>(totalSlots + 1, -1)
        );

        // Start recursion from first robot and first factory slot
        return solve(0, 0, robot, factoryPositions, dp);
    }
};
