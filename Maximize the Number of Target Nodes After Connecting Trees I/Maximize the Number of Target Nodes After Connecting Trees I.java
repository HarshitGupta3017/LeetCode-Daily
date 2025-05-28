// Solution for Maximize the Number of Target Nodes After Connecting Trees I in JAVA

class Solution {
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int[] targetsFromTree1 = computeTargetNodesPerNode(edges1, k);
        int[] targetsFromTree2 = computeTargetNodesPerNode(edges2, k - 1);
        int maxTargetsInTree2 = 0;
        for (int val : targetsFromTree2) maxTargetsInTree2 = Math.max(maxTargetsInTree2, val);
        for (int i = 0; i < targetsFromTree1.length; i++) targetsFromTree1[i] += maxTargetsInTree2;
        return targetsFromTree1;
    }

    private int[] computeTargetNodesPerNode(int[][] edges, int maxDist) {
        int totalNodes = edges.length + 1;
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], x -> new ArrayList<>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], x -> new ArrayList<>()).add(edge[0]);
        }
        int[] nodeTargetCounts = new int[totalNodes];
        for (int i = 0; i < totalNodes; i++) nodeTargetCounts[i] = BFS(i, adj, maxDist, totalNodes);
        return nodeTargetCounts;
    }

    private int BFS(int startNode, Map<Integer, List<Integer>> adj, int maxDist, int totalNodes) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{startNode, 0});
        boolean[] visited = new boolean[totalNodes];
        visited[startNode] = true;
        int count = 0;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int node = cur[0], dist = cur[1];
            if (dist > maxDist) continue;
            count++;
            for (int neighbor : adj.getOrDefault(node, new ArrayList<>())) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.offer(new int[]{neighbor, dist + 1});
                }
            }
        }
        return count;
    }
}
