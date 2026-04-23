// Solution for Sum of Distances in JAVA

class Solution {
    public long[] distance(int[] nums) {

        int n = nums.length;

        // Map value -> list of indices
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }

        long[] result = new long[n];

        // Process each group
        for (List<Integer> indices : map.values()) {

            int size = indices.size();

            long[] prefix = new long[size];
            prefix[0] = indices.get(0);

            for (int i = 1; i < size; i++) {
                prefix[i] = prefix[i - 1] + indices.get(i);
            }

            for (int i = 0; i < size; i++) {

                int currIndex = indices.get(i);

                long left = 0;
                if (i > 0) {
                    left = (long) i * currIndex - prefix[i - 1];
                }

                long right = 0;
                if (i < size - 1) {
                    int rightCount = size - i - 1;
                    long rightSum = prefix[size - 1] - prefix[i];
                    right = rightSum - (long) rightCount * currIndex;
                }

                result[currIndex] = left + right;
            }
        }

        return result;
    }
}
