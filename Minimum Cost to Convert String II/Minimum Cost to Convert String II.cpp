// Solution for Minimum Cost to Convert String II in CPP

class Solution {
public:

    using ll = long long;

    // A very large value to represent "infinity"
    // Used when conversion is impossible
    const ll INF = 1e10;

    // Pair for Dijkstra: {cost_so_far, current_string}
    using State = pair<ll, string>;

    /*
        Dijkstra on STRING GRAPH
        ------------------------
        Finds the minimum cost to convert string `start`
        into string `end` using allowed transformations.

        Graph:
        original[i] -> changed[i] with cost[i]

        Memoization (dpDijkstra) is used to avoid
        recomputing shortest paths repeatedly.
    */
    ll dijkstra(
        string& start,
        string& end,
        unordered_map<string, vector<pair<string, ll>>>& graph,
        unordered_map<string, unordered_map<string, ll>>& dpDijkstra
    ) {

        // If already computed, reuse result
        if (dpDijkstra[start].count(end)) {
            return dpDijkstra[start][end];
        }

        // Min-heap for Dijkstra
        priority_queue<State, vector<State>, greater<State>> minHeap;

        // Stores minimum cost to reach each string
        unordered_map<string, ll> minCost;

        // Starting point
        minCost[start] = 0;
        minHeap.push({0, start});

        while (!minHeap.empty()) {

            auto [currCost, currString] = minHeap.top();
            minHeap.pop();

            // If target reached, we can stop early
            if (currString == end) break;

            // Explore all transformations from currString
            for (const auto& edge : graph[currString]) {

                string nextString = edge.first;
                ll edgeCost = edge.second;

                ll newCost = currCost + edgeCost;

                // Relaxation step
                if (!minCost.count(nextString) || newCost < minCost[nextString]) {
                    minCost[nextString] = newCost;
                    minHeap.push({newCost, nextString});
                }
            }
        }

        // Store result in memo table
        return dpDijkstra[start][end] =
            minCost.count(end) ? minCost[end] : INF;
    }

    /*
        DP over source string index
        ---------------------------
        solve(idx) = minimum cost to convert
        source[idx ... end] -> target[idx ... end]

        At each index, we try:
        1) Skip single character if already equal
        2) Apply any valid substring transformation
    */
    ll solve(
        int idx,
        string& source,
        string& target,
        unordered_map<string, vector<pair<string, ll>>>& graph,
        set<int>& validLengths,
        vector<ll>& dp,
        unordered_map<string, unordered_map<string, ll>>& dpDijkstra
    ) {

        // Base case: processed entire string
        if (idx == source.size()) return 0;

        // Memoization check
        if (dp[idx] != -1) return dp[idx];

        ll answer = INF;

        /*
            Case 1:
            Characters already match → no cost
            Move forward by 1
        */
        if (source[idx] == target[idx]) {
            answer = solve(idx + 1, source, target, graph,
                           validLengths, dp, dpDijkstra);
        }

        /*
            Case 2:
            Try all possible substring lengths
            that exist in original[] list
        */
        for (int len : validLengths) {

            // Out of bounds check
            if (idx + len > source.size()) break;

            // Extract substrings
            string sourceSub = source.substr(idx, len);
            string targetSub = target.substr(idx, len);

            // If no transformation starts from sourceSub, skip
            if (!graph.count(sourceSub)) continue;

            // Find min cost to transform sourceSub → targetSub
            ll transformCost = dijkstra(
                sourceSub, targetSub, graph, dpDijkstra
            );

            // If impossible, skip
            if (transformCost == INF) continue;

            // Combine cost + remaining suffix
            answer = min(
                answer,
                transformCost +
                solve(idx + len, source, target,
                      graph, validLengths, dp, dpDijkstra)
            );
        }

        // Store result for this index
        return dp[idx] = answer;
    }

    /*
        MAIN FUNCTION
        -------------
        Builds graph + starts DP
    */
    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {

        int n = source.size();

        /*
            Build graph:
            original[i] -> changed[i] with cost[i]
        */
        unordered_map<string, vector<pair<string, ll>>> graph;

        for (int i = 0; i < original.size(); i++) {
            graph[original[i]].push_back({changed[i], cost[i]});
        }

        /*
            Store all valid substring lengths
            so we only try meaningful sizes
        */
        set<int> validLengths;
        for (const string& s : original) {
            validLengths.insert(s.length());
        }

        // DP array: dp[i] = min cost from index i to end
        vector<ll> dp(n, -1);

        // Memo table for Dijkstra results
        unordered_map<string, unordered_map<string, ll>> dpDijkstra;

        ll result = solve(
            0, source, target,
            graph, validLengths,
            dp, dpDijkstra
        );

        return result == INF ? -1 : result;
    }
};
