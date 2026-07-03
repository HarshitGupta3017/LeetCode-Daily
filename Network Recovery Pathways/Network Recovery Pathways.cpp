// Solution for Network Recovery Pathways in CPP

class Solution {
public:
    using ll = long long;
    using P = pair<ll, int>;

    // Returns true if there exists a valid path from 0 to n-1 where:
    // - every edge on the path has cost >= minEdge (enforcing the minimum edge threshold), and
    // - the total recovery cost of all edges does not exceed k.
    // We run Dijkstra minimising total cost, skipping edges below the threshold.
    bool canReachWithMinEdge(int minEdge, int n, ll k,
                             unordered_map<int, vector<pair<int,int>>>& adj) {

        // minCost[node] = smallest total recovery cost found so far to reach node
        // while only using edges with cost >= minEdge.
        vector<ll> minCost(n, LLONG_MAX);
        priority_queue<P, vector<P>, greater<P>> minHeap;

        minCost[0] = 0;
        minHeap.push({0, 0});

        while (!minHeap.empty()) {
            auto [costSoFar, node] = minHeap.top();
            minHeap.pop();

            // Stale entry: a cheaper path to this node was already processed.
            if (costSoFar > minCost[node]) continue;

            // Bug fix: original returned false immediately when costSoFar > k,
            // which incorrectly aborted the search even though other heap entries
            // with lower costs might still lead to valid paths.
            // The correct fix is to skip only this specific entry if it exceeds k.
            if (costSoFar > k) continue;

            if (node == n - 1) return true;

            for (auto [neighbor, edgeCost] : adj[node]) {
                // Edges below the threshold would violate the minimum-edge constraint,
                // so we don't traverse them for this particular binary search midpoint.
                if (edgeCost < minEdge) continue;

                ll newCost = costSoFar + edgeCost;

                // Only enqueue if this path is strictly cheaper than what we've seen.
                if (newCost < minCost[neighbor]) {
                    minCost[neighbor] = newCost;
                    minHeap.push({newCost, neighbor});
                }
            }
        }

        // Destination was never reached within budget using edges >= minEdge.
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        // Only include edges where both endpoints are online.
        // Offline intermediate nodes are invalid per the problem constraints.
        unordered_map<int, vector<pair<int,int>>> adj;
        int lo = INT_MAX, hi = 0;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];

            // Node 0 and n-1 are always online, but intermediate nodes may not be.
            if (!online[u] || !online[v]) continue;

            adj[u].push_back({v, cost});

            // Binary search range spans the smallest to largest edge cost among
            // valid edges — the answer must lie within this interval.
            lo = min(lo, cost);
            hi = max(hi, cost);
        }

        if (lo == INT_MAX) return -1;  // no valid edges exist at all

        // Binary search on the minimum edge cost threshold.
        // If a path exists with all edges >= mid and total cost <= k, try higher.
        int result = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReachWithMinEdge(mid, n, k, adj)) {
                result = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return result;
    }
};
