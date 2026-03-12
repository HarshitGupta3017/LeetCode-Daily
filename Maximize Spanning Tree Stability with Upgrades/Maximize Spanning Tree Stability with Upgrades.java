// Solution for Maximize Spanning Tree Stability with Upgrades in JAVA

class DSU {

    int[] parent;
    int[] rankValue;

    DSU(int n) {

        parent = new int[n];
        rankValue = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rankValue[i] = 1;
        }
    }

    int findParent(int node) {

        if (parent[node] == node)
            return node;

        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    boolean unite(int nodeA, int nodeB) {

        int rootA = findParent(nodeA);
        int rootB = findParent(nodeB);

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
}

class Solution {

    boolean canBuildStableTree(
        int totalNodes,
        int[][] edges,
        int upgradesAvailable,
        int targetStability
    ) {

        DSU dsu = new DSU(totalNodes);

        List<int[]> upgradeEligibleEdges = new ArrayList<>();

        for (int[] edge : edges) {

            int nodeU = edge[0];
            int nodeV = edge[1];
            int strength = edge[2];
            int mustInclude = edge[3];

            if (mustInclude == 1) {

                if (strength < targetStability)
                    return false;

                dsu.unite(nodeU, nodeV);
            }
            else {

                if (strength >= targetStability) {
                    dsu.unite(nodeU, nodeV);
                }
                else if (2 * strength >= targetStability) {
                    upgradeEligibleEdges.add(new int[]{nodeU, nodeV});
                }
            }
        }

        for (int[] edge : upgradeEligibleEdges) {

            int nodeU = edge[0];
            int nodeV = edge[1];

            if (dsu.findParent(nodeU) != dsu.findParent(nodeV)) {

                if (upgradesAvailable == 0)
                    return false;

                dsu.unite(nodeU, nodeV);
                upgradesAvailable--;
            }
        }

        int rootComponent = dsu.findParent(0);

        for (int node = 1; node < totalNodes; node++) {
            if (dsu.findParent(node) != rootComponent)
                return false;
        }

        return true;
    }

    public int maxStability(int n, int[][] edges, int k) {

        DSU validationDSU = new DSU(n);

        int bestStability = -1;

        int leftBound = Integer.MAX_VALUE;
        int rightBound = Integer.MIN_VALUE;

        for (int[] edge : edges) {

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

            leftBound = Math.min(leftBound, strength);
            rightBound = Math.max(rightBound, strength);
        }

        rightBound *= 2;

        while (leftBound <= rightBound) {

            int midStability = leftBound + (rightBound - leftBound) / 2;

            if (canBuildStableTree(n, edges, k, midStability)) {

                bestStability = midStability;
                leftBound = midStability + 1;
            }
            else {
                rightBound = midStability - 1;
            }
        }

        return bestStability;
    }
}
