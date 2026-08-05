// Solution for Remove Methods From Project in CPP

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        // inDegree[v] counts how many methods invoke v.
        // After BFS marks the suspicious group, any suspicious method with
        // inDegree > 0 is still being called from outside the group —
        // meaning the group cannot be safely removed.
        vector<int> inDegree(n, 0);

        for (const auto& edge : invocations) {
            int caller = edge[0], callee = edge[1];
            adj[caller].push_back(callee);
            inDegree[callee]++;
        }

        // BFS from k to find every method reachable from k (directly or indirectly).
        // These are all considered suspicious because bug k can propagate through them.
        vector<bool> suspicious(n, false);
        queue<int> bfsQueue;

        suspicious[k] = true;
        bfsQueue.push(k);

        while (!bfsQueue.empty()) {
            int method = bfsQueue.front();
            bfsQueue.pop();

            for (int callee : adj[method]) {
                // Decrement inDegree to track whether any non-suspicious method
                // still points into this suspicious callee after BFS completes.
                inDegree[callee]--;

                if (!suspicious[callee]) {
                    suspicious[callee] = true;
                    bfsQueue.push(callee);
                }
            }
        }

        // If any suspicious method still has inDegree > 0 after BFS, it means
        // a non-suspicious method invokes it — we cannot remove the group at all.
        for (int method = 0; method < n; method++) {
            if (suspicious[method] && inDegree[method] > 0) {
                // Return all methods unchanged — no removal takes place.
                vector<int> allMethods(n);
                iota(allMethods.begin(), allMethods.end(), 0);
                return allMethods;
            }
        }

        // Safe to remove: return only the non-suspicious methods.
        vector<int> remaining;
        for (int method = 0; method < n; method++) {
            if (!suspicious[method])
                remaining.push_back(method);
        }
        return remaining;
    }
};
