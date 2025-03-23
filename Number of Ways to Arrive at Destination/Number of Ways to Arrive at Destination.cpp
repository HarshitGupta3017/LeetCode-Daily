// Solution for Number of Ways to Arrive at Destination in CPP

class Solution {
public:
    using LL = pair<long long, int>;
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& edge: roads) {
            int u = edge[0], v = edge[1], time = edge[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        vector<long long> res(n, LLONG_MAX);
        vector<int> pathCount(n, 0);
        res[0] = 0;
        pathCount[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [currTime, currNode] = pq.top();
            pq.pop();
            for (const auto& vec: adj[currNode]) {
                auto& [ngbr, roadTime] = vec;
                if (currTime + roadTime < res[ngbr]) {
                    res[ngbr] = currTime + roadTime;
                    pq.push({res[ngbr], ngbr});
                    pathCount[ngbr] = pathCount[currNode];
                } else if (currTime + roadTime == res[ngbr]) {
                    pathCount[ngbr] = (pathCount[ngbr] + pathCount[currNode]) % M;
                }
            }
        }
        return pathCount[n - 1];
    }
};
