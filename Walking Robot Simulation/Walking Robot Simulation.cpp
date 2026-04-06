// Solution for Walking Robot Simulation in CPP

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        /*
        ============================================================
        STEP 1: Store obstacles for O(1) lookup
        ============================================================

        We convert (x, y) → "x_y" string for hashing
        */
        unordered_set<string> obstacleSet;

        for (const auto& obs : obstacles) {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            obstacleSet.insert(key);
        }

        /*
        ============================================================
        STEP 2: Initialize robot state
        ============================================================
        */
        int x = 0, y = 0;                 // current position
        int maxDistanceSquared = 0;       // answer

        /*
            Direction vector (dx, dy)

            Initially facing NORTH → (0, +1)
        */
        pair<int, int> direction = {0, 1};

        /*
        ============================================================
        STEP 3: Process each command
        ============================================================
        */
        for (int command : commands) {

            /*
            ------------------------------------------------------------
            TURN LEFT (90°)
            (dx, dy) → (-dy, dx)
            ------------------------------------------------------------
            */
            if (command == -2) {
                direction = {-direction.second, direction.first};
            }

            /*
            ------------------------------------------------------------
            TURN RIGHT (90°)
            (dx, dy) → (dy, -dx)
            ------------------------------------------------------------
            */
            else if (command == -1) {
                direction = {direction.second, -direction.first};
            }

            /*
            ------------------------------------------------------------
            MOVE FORWARD step-by-step
            ------------------------------------------------------------
            */
            else {

                /*
                    IMPORTANT:
                    Move ONE STEP at a time (not jump directly)

                    Because obstacle may be in between
                */
                while (command--) {

                    int nextX = x + direction.first;
                    int nextY = y + direction.second;

                    string key = to_string(nextX) + "_" + to_string(nextY);

                    /*
                        If obstacle → STOP movement immediately
                    */
                    if (obstacleSet.count(key)) break;

                    /*
                        Otherwise move
                    */
                    x = nextX;
                    y = nextY;
                }
            }

            /*
            ------------------------------------------------------------
            Update max distance from origin
            ------------------------------------------------------------
            */
            maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
        }

        return maxDistanceSquared;
    }
};
