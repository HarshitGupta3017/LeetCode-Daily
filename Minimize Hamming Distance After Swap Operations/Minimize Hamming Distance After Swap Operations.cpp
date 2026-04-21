// Solution for Minimize Hamming Distance After Swap Operations in CPP

class DSU {
public:
    vector<int> parent;
    vector<int> rankValue;

    DSU(int totalNodes) {

        parent.resize(totalNodes);
        rankValue.resize(totalNodes, 1);

        // Initially, each node is its own parent (separate component)
        for (int node = 0; node < totalNodes; node++) {
            parent[node] = node;
        }
    }

    // Find with path compression
    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // Union by rank
    bool unite(int nodeA, int nodeB) {

        int rootA = findParent(nodeA);
        int rootB = findParent(nodeB);

        // Already in same component
        if (rootA == rootB)
            return false;

        // Attach smaller tree under larger tree
        if (rankValue[rootA] < rankValue[rootB]) {
            parent[rootA] = rootB;
        }
        else if (rankValue[rootA] > rankValue[rootB]) {
            parent[rootB] = rootA;
        }
        else {
            parent[rootB] = rootA;
            rankValue[rootA]++;
        }

        return true;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source,
                               vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {

        int totalElements = source.size();

        // Step 1: Build DSU based on allowed swaps
        DSU dsu(totalElements);
        for (auto& swapPair : allowedSwaps) {
            dsu.unite(swapPair[0], swapPair[1]);
        }

        // Step 2: Group indices by their connected component
        unordered_map<int, vector<int>> componentMap;

        for (int index = 0; index < totalElements; index++) {
            int root = dsu.findParent(index);
            componentMap[root].push_back(index);
        }

        int minimumHammingDistance = 0;

        // Step 3: Process each component independently
        for (const auto& component : componentMap) {

            const vector<int>& indices = component.second;

            // Frequency map for values in source within this component
            unordered_map<int, int> frequencyMap;

            for (int idx : indices) {
                frequencyMap[source[idx]]++;
            }

            // Try to match target values using available frequencies
            for (int idx : indices) {
                int targetValue = target[idx];

                if (frequencyMap[targetValue] > 0) {
                    // Match found → reduce frequency
                    frequencyMap[targetValue]--;
                } else {
                    // No match possible → contributes to Hamming distance
                    minimumHammingDistance++;
                }
            }
        }

        return minimumHammingDistance;
    }
};
