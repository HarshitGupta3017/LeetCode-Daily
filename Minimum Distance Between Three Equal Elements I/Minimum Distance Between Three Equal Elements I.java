// Solution for Minimum Distance Between Three Equal Elements I in JAVA

class Solution {
    public int minimumDistance(int[] nums) {
        // Map each value to list of indices
        Map<Integer, List<Integer>> valueToIndices = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            valueToIndices
                .computeIfAbsent(nums[i], k -> new ArrayList<>())
                .add(i);
        }

        int minimumDistance = Integer.MAX_VALUE;

        // Iterate over each value
        for (List<Integer> indices : valueToIndices.values()) {
            if (indices.size() < 3) continue;

            for (int left = 0; left + 2 < indices.size(); left++) {
                int right = left + 2;
                int currentDistance = 2 * (indices.get(right) - indices.get(left));
                minimumDistance = Math.min(minimumDistance, currentDistance);
            }
        }

        return (minimumDistance == Integer.MAX_VALUE) ? -1 : minimumDistance;
    }
}
