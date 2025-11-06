// Solution for Power Grid Maintenance in JAVA

class Solution {
    int[] parent, rankArr;
    
    // 🔹 Find function with path compression
    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    // 🔹 Union function using rank optimization
    void unionNodes(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) return;

        if (rankArr[rootA] < rankArr[rootB]) {
            parent[rootA] = rootB;
        } else if (rankArr[rootA] > rankArr[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rankArr[rootA]++;
        }
    }

    // 🔹 Main logic
    public int[] processQueries(int totalStations, int[][] connections, int[][] queries) {
        parent = new int[totalStations + 1];
        rankArr = new int[totalStations + 1];
        
        // Initialize DSU
        for (int i = 1; i <= totalStations; i++) {
            parent[i] = i;
            rankArr[i] = 0;
        }
        
        // Build connected components
        for (int[] edge : connections) {
            unionNodes(edge[0], edge[1]);
        }
        
        // 🔹 Maintain online stations per component using TreeSet
        List<TreeSet<Integer>> componentStations = new ArrayList<>();
        for (int i = 0; i <= totalStations; i++) {
            componentStations.add(new TreeSet<>());
        }
        
        // Initially, all stations online
        for (int station = 1; station <= totalStations; station++) {
            int root = find(station);
            componentStations.get(root).add(station);
        }
        
        boolean[] isOnline = new boolean[totalStations + 1];
        Arrays.fill(isOnline, true);
        
        List<Integer> result = new ArrayList<>();
        
        // Process each query
        for (int[] query : queries) {
            int type = query[0];
            int station = query[1];
            int root = find(station);
            
            if (type == 1) {
                // 🟢 Maintenance check
                if (isOnline[station]) {
                    result.add(station);
                } else {
                    TreeSet<Integer> activeSet = componentStations.get(root);
                    if (!activeSet.isEmpty()) {
                        result.add(activeSet.first());
                    } else {
                        result.add(-1);
                    }
                }
            } else if (type == 2) {
                // 🔴 Take station offline
                if (isOnline[station]) {
                    isOnline[station] = false;
                    componentStations.get(root).remove(station);
                }
            }
        }
        
        // Convert to int[]
        return result.stream().mapToInt(i -> i).toArray();
    }
}
