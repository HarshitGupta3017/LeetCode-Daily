// Solution for Number of Ways to Arrive at Destination in JAVA

class Solution {
    private static final int MOD = 1_000_000_007;
    public int countPaths(int n, int[][] roads) {
        Map<Integer, List<int[]>> adj = new HashMap<>();
        for (int[] edge: roads) {
            int u = edge[0], v = edge[1], time = edge[2];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, time});
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[]{u, time});
        }
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        long[] res = new long[n];
        Arrays.fill(res, Long.MAX_VALUE);
        int[] pathCount = new int[n];
        res[0] = 0;
        pathCount[0] = 1;
        pq.add(new long[]{0, 0});
        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long currTime = curr[0];
            int currNode = (int) curr[1];
            for (int[] vec: adj.getOrDefault(currNode, new ArrayList<>())) {
                int ngbr = vec[0], roadTime = vec[1];
                if (currTime + roadTime < res[ngbr]) {
                    res[ngbr] = currTime + roadTime;
                    pq.add(new long[]{res[ngbr], ngbr});
                    pathCount[ngbr] = pathCount[currNode];
                } else if (currTime + roadTime == res[ngbr]) {
                    pathCount[ngbr] = (pathCount[ngbr] + pathCount[currNode]) % MOD;
                }
            }
        }
        return pathCount[n - 1];
    }
}
