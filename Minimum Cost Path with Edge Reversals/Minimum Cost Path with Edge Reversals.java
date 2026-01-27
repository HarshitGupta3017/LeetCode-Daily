// Solution for Minimum Cost Path with Edge Reversals in JAVA

class Solution {
    
    public int minCost(int n, int[][] edges) {

        // Build adjacency list: node -> list of {neighbor, weight}
        Map<Integer, List<int[]>> adj = new HashMap<>();
        for (int i = 0; i < n; i++) adj.put(i, new ArrayList<>());

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Normal forward edge
            adj.get(u).add(new int[]{v, w});

            // Switch-reversed edge from v -> u with double cost
            adj.get(v).add(new int[]{u, 2 * w});
        }

        // Dijkstra's setup: min-heap priority queue
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int[] minDist = new int[n];
        Arrays.fill(minDist, Integer.MAX_VALUE);

        pq.offer(new int[]{0, 0}); // {cost, node}
        minDist[0] = 0;

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int currCost = top[0];
            int currNode = top[1];

            // Early stopping if we reach target
            if (currNode == n - 1) return currCost;

            for (int[] neighborInfo : adj.get(currNode)) {
                int neighbor = neighborInfo[0];
                int edgeCost = neighborInfo[1];
                int newCost = currCost + edgeCost;

                if (newCost < minDist[neighbor]) {
                    minDist[neighbor] = newCost;
                    pq.offer(new int[]{newCost, neighbor});
                }
            }
        }

        return -1; // unreachable
    }
}
