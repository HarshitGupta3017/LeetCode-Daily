// Solution for Find X-Sum of All K-Long Subarrays I in JAVA

import java.util.*;

class Solution {

    // Helper function to compute x-sum for current frequency map
    private int findSum(Map<Integer, Integer> freqMap, int x) {
        // Min-heap storing [frequency, value]
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) return a[1] - b[1]; // If freq same, smaller value first
            return a[0] - b[0]; // Otherwise, smaller freq first
        });

        // Build heap and maintain only top x elements
        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {
            minHeap.offer(new int[]{entry.getValue(), entry.getKey()});
            if (minHeap.size() > x) {
                minHeap.poll();
            }
        }

        // Calculate x-sum
        int sum = 0;
        while (!minHeap.isEmpty()) {
            int[] top = minHeap.poll();
            sum += top[0] * top[1];
        }
        return sum;
    }

    public int[] findXSum(int[] nums, int k, int x) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        List<Integer> resultList = new ArrayList<>();
        int left = 0;

        // Sliding window traversal
        for (int right = 0; right < nums.length; right++) {
            freqMap.put(nums[right], freqMap.getOrDefault(nums[right], 0) + 1);

            // When window size reaches k
            if (right - left + 1 == k) {
                resultList.add(findSum(freqMap, x));

                // Slide window forward
                freqMap.put(nums[left], freqMap.get(nums[left]) - 1);
                if (freqMap.get(nums[left]) == 0) {
                    freqMap.remove(nums[left]);
                }
                left++;
            }
        }

        // Convert result list to int array
        int[] result = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            result[i] = resultList.get(i);
        }
        return result;
    }
}
