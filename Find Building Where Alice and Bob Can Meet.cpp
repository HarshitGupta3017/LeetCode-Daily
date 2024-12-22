class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> result(queries.size(), -1); // Initialize result with -1
        vector<vector<pair<int, int>>> deferredQueries(n); // Store deferred queries for each building

        // Step 1: Process each query
        for (int i = 0; i < queries.size(); ++i) {
            int alice = queries[i][0], bob = queries[i][1];

            // Ensure alice is the smaller index
            if (alice > bob) swap(alice, bob);

            // If directly solvable, update the result
            if (alice == bob || heights[alice] < heights[bob]) {
                result[i] = bob;
            } else {
                // Defer this query for later
                deferredQueries[bob].emplace_back(heights[alice], i);
            }
        }

        // Step 2: Use a min-heap to handle deferred queries
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (int i = 0; i < n; ++i) {
            // Add all deferred queries for the current building
            for (const auto& query : deferredQueries[i]) {
                minHeap.push(query);
            }

            // Process the heap: resolve queries where heights[i] is tall enough
            while (!minHeap.empty() && minHeap.top().first < heights[i]) {
                auto [deferredHeight, queryIndex] = minHeap.top();
                minHeap.pop();
                result[queryIndex] = i; // Update result with the current building
            }
        }

        return result;
    }
};
