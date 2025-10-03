// Solution for Trapping Rain Water II in CPP

class Solution {
public:
    // Alias: store {height, {row, col}} inside the priority queue
    using Cell = pair<int, pair<int, int>>;

    // Directions to move: left, right, down, up
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();

        // Min-heap (priority queue) sorted by height of boundary cell
        priority_queue<Cell, vector<Cell>, greater<Cell>> minHeap;

        // Visited matrix to avoid processing the same cell multiple times
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Step 1: Add boundary cells (left & right columns) into the min-heap
        for (int row = 0; row < rows; row++) {
            for (int col : {0, cols - 1}) {
                minHeap.push({heightMap[row][col], {row, col}});
                visited[row][col] = true; // mark boundary as visited
            }
        }

        // Step 2: Add boundary cells (top & bottom rows) into the min-heap
        for (int col = 0; col < cols; col++) {
            for (int row : {0, rows - 1}) {
                minHeap.push({heightMap[row][col], {row, col}});
                visited[row][col] = true; // mark boundary as visited
            }
        }

        int trappedWater = 0;

        // Step 3: Process cells in increasing order of height
        while (!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();

            int boundaryHeight = current.first;      // Height of current boundary
            int row = current.second.first;          // Row index
            int col = current.second.second;         // Column index

            // Step 4: Explore 4 neighboring cells
            for (const auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                // Skip if out of bounds or already visited
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || visited[newRow][newCol]) {
                    continue;
                }

                // If neighbor is lower than boundary, water can be trapped
                trappedWater += max(boundaryHeight - heightMap[newRow][newCol], 0);

                // Push the neighbor into heap with updated effective boundary height
                // The new boundary height is the max of current boundary and neighbor’s own height
                minHeap.push({max(boundaryHeight, heightMap[newRow][newCol]), {newRow, newCol}});

                visited[newRow][newCol] = true; // mark as processed
            }
        }

        return trappedWater; // Final total trapped water
    }
};
