// Solution for Largest Color Value in a Directed Graph in JAVA

class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[n];
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            indegree[v]++;
        }

        int[][] colorFreq = new int[n][26];
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
                colorFreq[i][colors.charAt(i) - 'a'] = 1;
            }
        }

        int maxColorCount = 0, visitedNodes = 0;
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            visitedNodes++;
            maxColorCount = Math.max(maxColorCount, colorFreq[curr][colors.charAt(curr) - 'a']);
            for (int neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
                for (int c = 0; c < 26; c++) {
                    int add = (colors.charAt(neighbor) - 'a' == c) ? 1 : 0;
                    colorFreq[neighbor][c] = Math.max(colorFreq[neighbor][c], colorFreq[curr][c] + add);
                }
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) queue.offer(neighbor);
            }
        }

        return visitedNodes == n ? maxColorCount : -1;
    }
}
