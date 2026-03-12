// Solution for Maximize Spanning Tree Stability with Upgrades in CPP

/*
    Disjoint Set Union (Union-Find) structure
    Used to efficiently maintain connected components
    while building the spanning tree.
*/
class DSU {
public:
    vector<int> parent;
    vector<int> rankValue;

    DSU(int n) {

        parent.resize(n);
        rankValue.resize(n, 1);

        // Initially each node is its own parent
        for (int node = 0; node < n; node++) {
            parent[node] = node;
        }
    }

    /*
        Find representative (root) of the component
        Uses path compression to make future queries faster
    */
    int findParent(int node) {

        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    /*
        Union two components if they are different
        Uses union-by-rank to keep tree shallow
    */
    bool unite(int nodeA, int nodeB) {

        int rootA = findParent(nodeA);
        int rootB = findParent(nodeB);

        // already connected
        if (rootA == rootB)
            return false;

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

    /*
        Check if we can build a valid spanning tree
        such that every edge used has strength >= targetStability
    */
    bool canBuildStableTree(
        int totalNodes,
        vector<vector<int>>& edges,
        int upgradesAvailable,
        int targetStability
    ) {

        DSU dsu(totalNodes);

        /*
            Edges that are not strong enough but could
            become strong enough after a single upgrade.
        */
        vector<pair<int,int>> upgradeEligibleEdges;

        /*
            Step 1:
            Process mandatory edges first.
            These edges MUST be included in the spanning tree
            and cannot be upgraded.
        */
        for (const auto &edge : edges) {

            int nodeU = edge[0];
            int nodeV = edge[1];
            int strength = edge[2];
            int mustInclude = edge[3];

            if (mustInclude == 1) {

                /*
                    If a mandatory edge is weaker than the required
                    stability, the configuration is impossible
                    because mandatory edges cannot be upgraded.
                */
                if (strength < targetStability)
                    return false;

                dsu.unite(nodeU, nodeV);
            }
            else {

                /*
                    Case 1:
                    Edge already satisfies the strength requirement
                    → we can directly include it.
                */
                if (strength >= targetStability) {
                    dsu.unite(nodeU, nodeV);
                }

                /*
                    Case 2:
                    Edge is currently weak but could become valid
                    after one upgrade.
                */
                else if (2 * strength >= targetStability) {
                    upgradeEligibleEdges.push_back({nodeU, nodeV});
                }

                /*
                    Case 3:
                    Even after upgrade it is too weak
                    → ignore it completely.
                */
            }
        }

        /*
            Step 2:
            Use upgrade edges only if they help connect
            different components and we still have upgrades left.
        */
        for (const auto &edge : upgradeEligibleEdges) {

            int nodeU = edge.first;
            int nodeV = edge.second;

            if (dsu.findParent(nodeU) != dsu.findParent(nodeV)) {

                if (upgradesAvailable == 0)
                    return false;

                dsu.unite(nodeU, nodeV);
                upgradesAvailable--;
            }
        }

        /*
            Step 3:
            Verify that all nodes belong to the same component.
            If yes → a spanning tree exists under this stability.
        */
        int rootComponent = dsu.findParent(0);

        for (int node = 1; node < totalNodes; node++) {
            if (dsu.findParent(node) != rootComponent)
                return false;
        }

        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        DSU validationDSU(n);

        int bestStability = -1;

        /*
            Binary search range for stability.
            Minimum possible strength among edges
            to maximum possible strength after upgrade.
        */
        int leftBound = INT_MAX;
        int rightBound = INT_MIN;

        /*
            Step 1:
            Validate mandatory edges do not create cycles.
            If they do, building a spanning tree is impossible.
        */
        for (const auto &edge : edges) {

            int nodeU = edge[0];
            int nodeV = edge[1];
            int strength = edge[2];
            int mustInclude = edge[3];

            if (mustInclude == 1) {

                if (validationDSU.findParent(nodeU) ==
                    validationDSU.findParent(nodeV)) {
                    return -1;
                }

                validationDSU.unite(nodeU, nodeV);
            }

            leftBound = min(leftBound, strength);
            rightBound = max(rightBound, strength);
        }

        /*
            Maximum strength possible after upgrade
        */
        rightBound *= 2;

        /*
            Step 2:
            Binary search the maximum possible stability.
        */
        while (leftBound <= rightBound) {

            int midStability = leftBound + (rightBound - leftBound) / 2;

            if (canBuildStableTree(n, edges, k, midStability)) {

                /*
                    Current stability is achievable.
                    Try to increase it.
                */
                bestStability = midStability;
                leftBound = midStability + 1;
            }
            else {

                /*
                    Current stability is too high.
                    Reduce search space.
                */
                rightBound = midStability - 1;
            }
        }

        return bestStability;
    }
};
