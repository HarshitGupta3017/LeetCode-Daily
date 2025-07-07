// Solution for Maximum Number of Events That Can Be Attended in JAVA

class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, Comparator.comparingInt(a -> a[0]));
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int day = events[0][0];
        int totalAttended = 0;
        int i = 0, n = events.length;

        while (i < n || !minHeap.isEmpty()) {
            if (minHeap.isEmpty()) {
                day = events[i][0];
            }

            while (i < n && events[i][0] == day) {
                minHeap.offer(events[i][1]);
                i++;
            }

            if (!minHeap.isEmpty()) {
                minHeap.poll();
                totalAttended++;
            }

            day++;

            while (!minHeap.isEmpty() && minHeap.peek() < day) {
                minHeap.poll();
            }
        }

        return totalAttended;
    }
}
