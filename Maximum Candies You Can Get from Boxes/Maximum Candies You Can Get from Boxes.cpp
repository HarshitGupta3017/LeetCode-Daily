// Solution for Maximum Candies You Can Get from Boxes in CPP

class Solution {
public:
    // DFS function to collect candies from a given box
    int dfs(
        int box,
        vector<int>& status,
        vector<int>& candies,
        vector<vector<int>>& keys,
        vector<vector<int>>& containedBoxes,
        vector<bool>& visited,
        unordered_set<int>& foundBoxes
    ) {
        // If we've already visited this box, skip it
        if (visited[box]) return 0;

        // If the box is locked, save it for future when we get its key
        if (status[box] == 0) {
            foundBoxes.insert(box);
            return 0;
        }

        // Mark the box as visited
        visited[box] = true;
        int collectedCandies = candies[box];  // Collect candies in current box

        // Recursively explore boxes found inside the current box
        for (int& innerBox : containedBoxes[box]) {
            collectedCandies += dfs(innerBox, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        // Use keys found in the current box
        for (int& unlockBox : keys[box]) {
            status[unlockBox] = 1;  // Mark the box as open
            // If we already found this box before (but it was locked), explore it now
            if (foundBoxes.count(unlockBox)) {
                collectedCandies += dfs(unlockBox, status, candies, keys, containedBoxes, visited, foundBoxes);
            }
        }

        return collectedCandies;
    }

    // Main function to calculate the maximum number of candies
    int maxCandies(
        vector<int>& status,
        vector<int>& candies,
        vector<vector<int>>& keys,
        vector<vector<int>>& containedBoxes,
        vector<int>& initialBoxes
    ) {
        int n = candies.size();
        int totalCandies = 0;

        vector<bool> visited(n, false);       // To avoid visiting the same box again
        unordered_set<int> foundBoxes;        // Boxes found but not yet openable

        // Start DFS from each initially available box
        for (const int& box : initialBoxes) {
            totalCandies += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        return totalCandies;
    }
};
