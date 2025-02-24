class Solution {
public:

    bool DfsBob(int curr, int t, unordered_map<int, int>& bobtime, vector<bool>& vis, unordered_map<int, vector<int>>& adj) {
        vis[curr] = true;
        bobtime[curr] = t;
        if (curr == 0) return true;
        for (const auto& ngbr: adj[curr]) {
            if (!vis[ngbr]) {
                if (DfsBob(ngbr, t + 1, bobtime, vis, adj)) return true;
            }
        }
        bobtime.erase(curr);
        return false;
    }

    void DfsAlice(int curr, int t, vector<bool>& vis, unordered_map<int, vector<int>>& adj, vector<int>& amount, int income, int& result, unordered_map<int, int>& bobtime) {
        vis[curr] = true;
        if (bobtime.find(curr) == bobtime.end() || t < bobtime[curr]) {
            income += amount[curr];
        } else if (t == bobtime[curr]) {
            income += (amount[curr] / 2);
        }
        if (adj[curr].size() == 1 && curr != 0) {
            result = max(result, income);
        }
        for (const auto& ngbr: adj[curr]) {
            if (!vis[ngbr]) {
                DfsAlice(ngbr, t + 1, vis, adj, amount, income, result, bobtime);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int, vector<int>> adj;
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int n = amount.size();
        unordered_map<int, int> bobtime;
        int startTime = 0;
        vector<bool> visited(n, false);
        DfsBob(bob, startTime, bobtime, visited, adj);
        visited.assign(n, false);
        int income = 0, result = INT_MIN, alicestart = 0, t = 0;
        DfsAlice(alicestart, t, visited, adj, amount, income, result, bobtime);
        return result;
    }
};
