// Solution for Minimum Cost to Convert String II in JAVA

class Solution {

    private static final long INF = (long) 1e10;

    // Dijkstra on string graph
    private long dijkstra(
            String start,
            String end,
            Map<String, List<Pair>> graph,
            Map<String, Map<String, Long>> dpDijkstra
    ) {

        // Memoized result
        dpDijkstra.putIfAbsent(start, new HashMap<>());
        if (dpDijkstra.get(start).containsKey(end)) {
            return dpDijkstra.get(start).get(end);
        }

        PriorityQueue<State> pq =
                new PriorityQueue<>(Comparator.comparingLong(a -> a.cost));

        Map<String, Long> minCost = new HashMap<>();
        minCost.put(start, 0L);
        pq.offer(new State(start, 0));

        while (!pq.isEmpty()) {
            State curr = pq.poll();

            if (curr.cost > minCost.get(curr.str)) continue;
            if (curr.str.equals(end)) break;

            if (!graph.containsKey(curr.str)) continue;

            for (Pair edge : graph.get(curr.str)) {
                long newCost = curr.cost + edge.cost;
                if (!minCost.containsKey(edge.str) ||
                        newCost < minCost.get(edge.str)) {
                    minCost.put(edge.str, newCost);
                    pq.offer(new State(edge.str, newCost));
                }
            }
        }

        long res = minCost.getOrDefault(end, INF);
        dpDijkstra.get(start).put(end, res);
        return res;
    }

    // DP over index
    private long solve(
            int idx,
            String source,
            String target,
            Map<String, List<Pair>> graph,
            Set<Integer> validLengths,
            long[] dp,
            Map<String, Map<String, Long>> dpDijkstra
    ) {

        if (idx == source.length()) return 0;
        if (dp[idx] != -1) return dp[idx];

        long ans = INF;

        // Case 1: characters match
        if (source.charAt(idx) == target.charAt(idx)) {
            ans = solve(idx + 1, source, target,
                        graph, validLengths, dp, dpDijkstra);
        }

        // Case 2: try substring transformations
        for (int len : validLengths) {
            if (idx + len > source.length()) break;

            String srcSub = source.substring(idx, idx + len);
            String tgtSub = target.substring(idx, idx + len);

            if (!graph.containsKey(srcSub)) continue;

            long cost = dijkstra(srcSub, tgtSub, graph, dpDijkstra);
            if (cost == INF) continue;

            ans = Math.min(ans,
                    cost + solve(idx + len, source, target,
                                 graph, validLengths, dp, dpDijkstra));
        }

        return dp[idx] = ans;
    }

    public long minimumCost(
            String source,
            String target,
            String[] original,
            String[] changed,
            int[] cost
    ) {

        Map<String, List<Pair>> graph = new HashMap<>();
        for (int i = 0; i < original.length; i++) {
            graph.computeIfAbsent(original[i], k -> new ArrayList<>())
                 .add(new Pair(changed[i], cost[i]));
        }

        Set<Integer> validLengths = new TreeSet<>();
        for (String s : original) {
            validLengths.add(s.length());
        }

        long[] dp = new long[source.length()];
        Arrays.fill(dp, -1);

        Map<String, Map<String, Long>> dpDijkstra = new HashMap<>();

        long res = solve(0, source, target,
                         graph, validLengths, dp, dpDijkstra);

        return res == INF ? -1 : res;
    }

    // Helper classes
    static class Pair {
        String str;
        long cost;
        Pair(String s, long c) {
            str = s;
            cost = c;
        }
    }

    static class State {
        String str;
        long cost;
        State(String s, long c) {
            str = s;
            cost = c;
        }
    }
}
