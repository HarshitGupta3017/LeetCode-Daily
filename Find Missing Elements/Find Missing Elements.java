// Solution for Find Missing Elements in JAVA

class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        // Load all present values into a hash set for O(1) membership checks.
        Set<Integer> present = new HashSet<>();
        for (int num : nums) {
            present.add(num);
        }

        // Find the minimum and maximum values.
        int rangeMin = Integer.MAX_VALUE;
        int rangeMax = Integer.MIN_VALUE;

        for (int num : nums) {
            rangeMin = Math.min(rangeMin, num);
            rangeMax = Math.max(rangeMax, num);
        }

        List<Integer> missing = new ArrayList<>();

        // Check all interior values.
        for (int val = rangeMin + 1; val < rangeMax; val++) {
            if (!present.contains(val)) {
                missing.add(val);
            }
        }

        return missing;
    }
}
