// Solution for Minimum Initial Energy to Finish Tasks in CPP

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        // Sort tasks by surplus (minimum - actual) in DESCENDING order
        // Surplus = how much energy "buffer" a task demands beyond what it costs
        // Example: task[1,3] → surplus=2, task[4,8] → surplus=4
        // Higher surplus tasks are more demanding to START, do them first
        // when your energy is still high
        auto sortBySurplusDescending = [](auto& a, auto& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
            //      ^surplus of a    ^surplus of b
            // a comes before b if a's surplus is HIGHER
        };
        sort(tasks.begin(), tasks.end(), sortBySurplusDescending);

        // minStartingEnergy = answer we're building
        // The minimum energy we must START WITH so that all tasks are doable
        int minStartingEnergy = 0;

        // energyConsumedSoFar = sum of actual costs of all tasks done BEFORE current one
        // Represents how much of the starting energy has already been "used up"
        // Example: tasks [1,3],[2,4] done → energyConsumedSoFar=1 before task 2
        int energyConsumedSoFar = 0;

        for (const auto& task : tasks) {

            int actualCost   = task[0];  // energy spent DOING this task
            int minimumToStart = task[1];  // energy needed TO BEGIN this task

            // To start THIS task, we need at least:
            //   energyConsumedSoFar + minimumToStart
            // Because starting energy - previous tasks' cost = current energy
            // We need current energy >= minimumToStart
            // → startingEnergy - energyConsumedSoFar >= minimumToStart
            // → startingEnergy >= energyConsumedSoFar + minimumToStart
            //
            // Example: spent 3 so far, task needs minimum 5
            // → must have started with at least 3+5=8
            minStartingEnergy = max(minStartingEnergy, energyConsumedSoFar + minimumToStart);

            // Mark this task's cost as consumed for future tasks
            // Example: task costs 2, future tasks see 2 more energy "gone"
            energyConsumedSoFar += actualCost;
        }

        return minStartingEnergy;
    }
};
