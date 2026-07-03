// Solution for Network Recovery Pathways in JAVA

class Solution {

    static class Pair {
        long cost;
        int node;

        Pair(long cost, int node) {
            this.cost = cost;
            this.node = node;
        }
    }

    // Returns true if there exists a valid path from 0 to n-1 where:
    // - every edge on the path has cost >= minEdge
    // - total recovery cost <= k
    private boolean canReachWithMinEdge(int minEdge, int n, long k,
                                        Map<Integer, List<int[]>> adj) {

        long[] minCost = new long[n];
        Arrays.fill(minCost, Long.MAX_VALUE);

        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a.cost));

        minCost[0] = 0;
        pq.offer(new Pair(0, 0));

        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            long costSoFar = curr.cost;
            int node = curr.node;

            if (costSoFar > minCost[node]) continue;
            if (costSoFar > k) continue;

            if (node == n - 1) return true;

            List<int[]> neighbors = adj.getOrDefault(node, Collections.emptyList());

            for (int[] edge : neighbors) {
                int next = edge[0];
                int edgeCost = edge[1];

                if (edgeCost < minEdge) continue;

                long newCost = costSoFar + edgeCost;

                if (newCost < minCost[next]) {
                    minCost[next] = newCost;
                    pq.offer(new Pair(newCost, next));
                }
            }
        }

        return false;
    }

    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {
        int n = online.length;

        Map<Integer, List<int[]>> adj = new HashMap<>();

        int lo = Integer.MAX_VALUE;
        int hi = 0;

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if (!online[u] || !online[v]) continue;

            adj.computeIfAbsent(u, x -> new ArrayList<>()).add(new int[]{v, cost});

            lo = Math.min(lo, cost);
            hi = Math.max(hi, cost);
        }

        if (lo == Integer.MAX_VALUE) return -1;

        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canReachWithMinEdge(mid, n, k, adj)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
}
