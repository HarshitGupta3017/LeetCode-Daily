// Solution for Jump Game IV in CPP

class Solution {
public:
    int minJumps(vector<int>& arr) {

        int totalElements = arr.size();

        // Store all indices corresponding to each value
        unordered_map<int, vector<int>> valueIndicesMap;

        for (int index = 0; index < totalElements; index++) {

            valueIndicesMap[arr[index]].push_back(index);
        }

        // Standard BFS setup
        queue<int> bfsQueue;
        bfsQueue.push(0);

        vector<bool> visited(totalElements, false);
        visited[0] = true;

        int steps = 0;

        while (!bfsQueue.empty()) {

            int currentLevelSize = bfsQueue.size();

            while (currentLevelSize--) {

                int currentIndex = bfsQueue.front();
                bfsQueue.pop();

                // Reached last index
                if (currentIndex == totalElements - 1) {

                    return steps;
                }

                // Move to previous index
                if (currentIndex - 1 >= 0 && !visited[currentIndex - 1]) {

                    visited[currentIndex - 1] = true;
                    bfsQueue.push(currentIndex - 1);
                }

                // Move to next index
                if (currentIndex + 1 < totalElements && !visited[currentIndex + 1]) {

                    visited[currentIndex + 1] = true;
                    bfsQueue.push(currentIndex + 1);
                }

                // Jump to all indices having same value
                for (const int& nextIndex : valueIndicesMap[arr[currentIndex]]) {

                    if (!visited[nextIndex]) {

                        visited[nextIndex] = true;
                        bfsQueue.push(nextIndex);
                    }
                }

                // Remove processed value group
                // to avoid repeated traversals
                valueIndicesMap.erase(arr[currentIndex]);
            }

            steps++;
        }

        return steps;
    }
};
