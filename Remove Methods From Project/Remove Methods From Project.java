// Solution for Remove Methods From Project in JAVA

class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        int[] inDegree = new int[n];

        for (int[] edge : invocations) {
            int caller = edge[0];
            int callee = edge[1];
            adj.get(caller).add(callee);
            inDegree[callee]++;
        }

        boolean[] suspicious = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();

        suspicious[k] = true;
        queue.offer(k);

        while (!queue.isEmpty()) {
            int method = queue.poll();

            for (int callee : adj.get(method)) {
                inDegree[callee]--;

                if (!suspicious[callee]) {
                    suspicious[callee] = true;
                    queue.offer(callee);
                }
            }
        }

        for (int method = 0; method < n; method++) {
            if (suspicious[method] && inDegree[method] > 0) {
                List<Integer> allMethods = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    allMethods.add(i);
                }
                return allMethods;
            }
        }

        List<Integer> remaining = new ArrayList<>();
        for (int method = 0; method < n; method++) {
            if (!suspicious[method]) {
                remaining.add(method);
            }
        }

        return remaining;
    }
}
