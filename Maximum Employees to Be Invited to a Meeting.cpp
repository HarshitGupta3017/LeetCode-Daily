class Solution {
public:

    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        int maxD = 0;
        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();
            for (const auto& ngbr: adj[curr]) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    q.push({ngbr, dist + 1});
                    maxD = max(maxD, dist + 1);
                }
            }
        }
        return maxD;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            int u = i, v = favorite[i];
            adj[v].push_back(u);
        }
        int maxCycle = 0, happyCouple = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_map<int, int> mp;
                int currNode = i, currNodeCount = 0;
                while (!vis[currNode]) {
                    vis[currNode] = true;
                    mp[currNode] = currNodeCount;
                    int nextNode = favorite[currNode];
                    currNodeCount++;
                    if (mp.count(nextNode)) {
                        int cycleLength = currNodeCount - mp[nextNode];
                        maxCycle = max(maxCycle, cycleLength);
                        if (cycleLength == 2) {
                            vector<bool> visNodes(n, false);
                            visNodes[currNode] = true;
                            visNodes[nextNode] = true;
                            happyCouple += 2 + BFS(currNode, adj, visNodes) + BFS(nextNode, adj, visNodes); 
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }
        return max(maxCycle, happyCouple);
    }
};
