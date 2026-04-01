// Solution for Robot Collisions in CPP

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        int totalRobots = positions.size();

        // Stores indices of robots sorted by their positions
        vector<int> sortedIndices(totalRobots);
        iota(sortedIndices.begin(), sortedIndices.end(), 0);

        // Sort indices based on robot positions (left → right)
        sort(sortedIndices.begin(), sortedIndices.end(), [&](int &a, int &b) {
            return positions[a] < positions[b];
        });

        // Stack to keep indices of robots moving to the right
        // These are potential candidates for collision with left-moving robots
        stack<int> rightMovingStack;

        // Traverse robots in increasing order of position
        for (const auto& currentIndex : sortedIndices) {

            // Case 1: Robot moving to the right → push to stack
            if (directions[currentIndex] == 'R') {
                rightMovingStack.push(currentIndex);
            } 
            // Case 2: Robot moving to the left → may collide
            else {

                // Continue collisions while:
                // 1. There exists a right-moving robot
                // 2. Current robot is still alive (health > 0)
                while (!rightMovingStack.empty() && healths[currentIndex] > 0) {

                    int rightRobotIndex = rightMovingStack.top();
                    rightMovingStack.pop();

                    // Compare healths to resolve collision
                    if (healths[rightRobotIndex] > healths[currentIndex]) {
                        // Right-moving robot survives
                        healths[rightRobotIndex] -= 1;
                        healths[currentIndex] = 0;

                        // Put it back as it can collide again later
                        rightMovingStack.push(rightRobotIndex);

                    } else if (healths[rightRobotIndex] < healths[currentIndex]) {
                        // Left-moving robot survives this collision
                        healths[rightRobotIndex] = 0;
                        healths[currentIndex] -= 1;

                        // Continue checking with next right-moving robot in stack

                    } else {
                        // Both robots have equal health → both destroyed
                        healths[rightRobotIndex] = 0;
                        healths[currentIndex] = 0;
                    }
                }
            }
        }

        // Collect surviving robots' healths in original input order
        vector<int> survivingHealths;

        for (int i = 0; i < totalRobots; i++) {
            if (healths[i] > 0) {
                survivingHealths.push_back(healths[i]);
            }
        }

        return survivingHealths;
    }
};
