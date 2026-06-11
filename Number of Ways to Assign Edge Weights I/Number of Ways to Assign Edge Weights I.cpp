// Solution for Number of Ways to Assign Edge Weights I in CPP

class Solution {
public:
    using ll = long long;
    static constexpr int MOD = 1e9 + 7;

    // Fast exponentiation: computes base^exp % MOD in O(log exp).
    // We halve the exponent each time so we don't multiply base exp times naively.
    ll power(ll base, ll exp) {
        if (exp == 0) return 1;

        ll half = power(base, exp / 2);
        ll result = (half * half) % MOD;

        // If exp is odd, one extra factor of base is left unaccounted for after halving.
        if (exp % 2 == 1)
            result = (result * base) % MOD;

        return result;
    }

    // Returns the depth of the deepest node in the subtree rooted at `node`,
    // counting edges (not nodes), with `parent` tracked to avoid going back up.
    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node, int parent) {
        int maxChildDepth = 0;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            maxChildDepth = max(maxChildDepth, getMaxDepth(adj, neighbor, node) + 1);
        }

        return maxChildDepth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // The path from root to the deepest node has exactly d edges.
        // Each edge is independently assigned 1 or 2, giving 2^d total combinations.
        // Exactly half of them produce an odd total, because for any assignment of
        // the first d-1 edges, there is exactly one choice for the last edge that
        // makes the sum odd. So the answer is always 2^d / 2 = 2^(d-1).
        int d = getMaxDepth(adj, 1, -1);

        return power(2, d - 1);
    }
};
