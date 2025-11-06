// Solution for Power Grid Maintenance in CPP

class Solution {
public:
    vector<int> parent, rankArr;

    // 🔹 Find function with path compression
    int Find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = Find(parent[node]);
    }

    // 🔹 Union function using rank optimization
    void Union(int a, int b) {
        int rootA = Find(a);
        int rootB = Find(b);

        if (rootA == rootB) return; // already in same component

        if (rankArr[rootA] < rankArr[rootB]) {
            parent[rootA] = rootB;
        } else if (rankArr[rootA] > rankArr[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rankArr[rootA]++;
        }
    }

    // 🔹 Main function to process power grid queries
    vector<int> processQueries(int totalStations, 
                               vector<vector<int>>& connections, 
                               vector<vector<int>>& queries) {
        
        // Initialize DSU structures
        parent.resize(totalStations + 1);
        rankArr.resize(totalStations + 1, 0);

        for (int i = 1; i <= totalStations; i++) {
            parent[i] = i;
        }

        // Build connected components using DSU
        for (const auto& edge : connections) {
            Union(edge[0], edge[1]);
        }

        // 🔹 Create a set for each connected component (stores online station IDs)
        vector<set<int>> componentStations(totalStations + 1);
        for (int station = 1; station <= totalStations; station++) {
            int root = Find(station);
            componentStations[root].insert(station);
        }

        // 🔹 Track station online/offline status
        vector<bool> isOnline(totalStations + 1, true);
        vector<int> result;

        // Process each query in order
        for (const auto& query : queries) {
            int type = query[0];
            int station = query[1];
            int root = Find(station);

            if (type == 1) {  
                // 🟢 Type 1: Maintenance check
                if (isOnline[station]) {
                    // Station resolves it by itself
                    result.push_back(station);
                } else {
                    // Find smallest operational station in same component
                    if (!componentStations[root].empty()) {
                        result.push_back(*componentStations[root].begin());
                    } else {
                        result.push_back(-1); // no online station left
                    }
                }
            } 
            else if (type == 2) {  
                // 🔴 Type 2: Take station offline
                if (isOnline[station]) {
                    isOnline[station] = false;
                    componentStations[root].erase(station); // remove from active set
                }
            }
        }

        return result;
    }
};
