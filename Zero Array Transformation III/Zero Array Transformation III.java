// Solution for Zero Array Transformation III in JAVA

class Solution {
    public int maxRemoval(int[] nums, int[][] queries) {
        int n = nums.length;
        int Q = queries.length;

        // Sort queries by starting index
        Arrays.sort(queries, (a, b) -> Integer.compare(a[0], b[0]));

        // Max-heap for query end indices
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        // Min-heap for ongoing queries
        PriorityQueue<Integer> past = new PriorityQueue<>();

        int j = 0, usedCount = 0;

        for (int i = 0; i < n; i++) {
            // Add all queries starting at current index i
            while (j < Q && queries[j][0] == i) {
                maxHeap.offer(queries[j][1]);
                j++;
            }

            // Apply past effects
            nums[i] -= past.size();

            // Apply active queries from maxHeap
            while (nums[i] > 0 && !maxHeap.isEmpty() && maxHeap.peek() >= i) {
                int end = maxHeap.poll();
                past.offer(end);
                usedCount++;
                nums[i]--;
            }

            if (nums[i] > 0) return -1;

            // Remove expired queries
            while (!past.isEmpty() && past.peek() <= i) {
                past.poll();
            }
        }

        return Q - usedCount; // Maximum queries that can be removed
    }
}
