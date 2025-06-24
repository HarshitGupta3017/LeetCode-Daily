// Solution for Find All K-Distant Indices in an Array in JAVA

class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> kDistantIndices = new ArrayList<>();
        int n = nums.length;
        int lastAdded = -1;

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int start = Math.max(0, j - k);
                int end = Math.min(n - 1, j + k);

                // Skip duplicates
                if (!kDistantIndices.isEmpty() && lastAdded >= start) {
                    start = lastAdded + 1;
                }

                for (int i = start; i <= end; i++) {
                    kDistantIndices.add(i);
                    lastAdded = i;
                }
            }
        }

        return kDistantIndices;
    }
}
