// Solution for Divide an Array Into Subarrays With Minimum Cost II in JAVA

class Solution {
    public long minimumCost(int[] nums, int k, int dist) {

        int n = nums.length;

        // TreeSet storing {value, index}
        TreeSet<long[]> minKElements = new TreeSet<>(
            (a, b) -> {
                if (a[0] != b[0]) return Long.compare(a[0], b[0]);
                return Long.compare(a[1], b[1]);
            }
        );

        TreeSet<long[]> remainingElements = new TreeSet<>(
            (a, b) -> {
                if (a[0] != b[0]) return Long.compare(a[0], b[0]);
                return Long.compare(a[1], b[1]);
            }
        );

        long currentSum = 0;
        int right = 1;

        // Initial window
        while (right - dist < 1) {
            minKElements.add(new long[]{nums[right], right});
            currentSum += nums[right];

            if (minKElements.size() > k - 1) {
                long[] largest = minKElements.last();
                minKElements.remove(largest);
                currentSum -= largest[0];
                remainingElements.add(largest);
            }
            right++;
        }

        long minCostForSubarrays = Long.MAX_VALUE;

        // Sliding window
        while (right < n) {

            minKElements.add(new long[]{nums[right], right});
            currentSum += nums[right];

            if (minKElements.size() > k - 1) {
                long[] largest = minKElements.last();
                minKElements.remove(largest);
                currentSum -= largest[0];
                remainingElements.add(largest);
            }

            minCostForSubarrays = Math.min(minCostForSubarrays, currentSum);

            long[] toRemove = new long[]{nums[right - dist], right - dist};

            if (minKElements.remove(toRemove)) {
                currentSum -= toRemove[0];

                if (!remainingElements.isEmpty()) {
                    long[] smallest = remainingElements.first();
                    remainingElements.remove(smallest);
                    minKElements.add(smallest);
                    currentSum += smallest[0];
                }
            } else {
                remainingElements.remove(toRemove);
            }

            right++;
        }

        return nums[0] + minCostForSubarrays;
    }
}
