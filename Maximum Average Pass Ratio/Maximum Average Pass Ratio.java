// Solution for Maximum Average Pass Ratio in JAVA

class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        int n = classes.length;

        // PriorityQueue with custom comparator (max-heap by delta)
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> Double.compare(delta(b[0], b[1]), delta(a[0], a[1]))
        );

        // Push all classes
        for (int[] c : classes) {
            pq.offer(new int[]{c[0], c[1]});
        }

        // Distribute extra students
        while (extraStudents-- > 0) {
            int[] c = pq.poll();
            c[0]++;  // one more pass
            c[1]++;  // total increases
            pq.offer(c);
        }

        // Calculate final average ratio
        double result = 0.0;
        for (int[] c : pq) {
            result += (double) c[0] / c[1];
        }
        return result / n;
    }

    // Helper function for delta calculation
    private double delta(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double) pass / total;
    }
}
