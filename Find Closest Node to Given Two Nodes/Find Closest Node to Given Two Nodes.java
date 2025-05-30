// Solution for Find Closest Node to Given Two Nodes in JAVA

class Solution {
    private int[] computeDistancesFromNode(int[] edges, int startNode, int totalNodes) {
        int[] distance = new int[totalNodes];
        Arrays.fill(distance, -1);
        distance[startNode] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(startNode);

        while (!queue.isEmpty()) {
            int current = queue.poll();
            int next = edges[current];
            if (next != -1 && distance[next] == -1) {
                distance[next] = distance[current] + 1;
                queue.offer(next);
            }
        }

        return distance;
    }

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length;

        int[] dist1 = computeDistancesFromNode(edges, node1, n);
        int[] dist2 = computeDistancesFromNode(edges, node2, n);

        int minMaxDist = Integer.MAX_VALUE;
        int closestNode = -1;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = Math.max(dist1[i], dist2[i]);
                if (maxDist < minMaxDist || (maxDist == minMaxDist && i < closestNode)) {
                    minMaxDist = maxDist;
                    closestNode = i;
                }
            }
        }

        return closestNode;
    }
}
