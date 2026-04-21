// Solution for Minimize Hamming Distance After Swap Operations in JAVA

class DSU {
    int[] parent;
    int[] rank;

    public DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    public int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    public boolean unite(int a, int b) {
        int rootA = findParent(a);
        int rootB = findParent(b);

        if (rootA == rootB) return false;

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }
}

class Solution {
    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;

        DSU dsu = new DSU(n);

        // Step 1: Union
        for (int[] swap : allowedSwaps) {
            dsu.unite(swap[0], swap[1]);
        }

        // Step 2: Group by components
        Map<Integer, List<Integer>> componentMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int root = dsu.findParent(i);
            componentMap.computeIfAbsent(root, k -> new ArrayList<>()).add(i);
        }

        int result = 0;

        // Step 3: Process each component
        for (List<Integer> indices : componentMap.values()) {

            Map<Integer, Integer> freq = new HashMap<>();

            for (int idx : indices) {
                freq.put(source[idx], freq.getOrDefault(source[idx], 0) + 1);
            }

            for (int idx : indices) {
                int val = target[idx];

                if (freq.getOrDefault(val, 0) > 0) {
                    freq.put(val, freq.get(val) - 1);
                } else {
                    result++;
                }
            }
        }

        return result;
    }
}
