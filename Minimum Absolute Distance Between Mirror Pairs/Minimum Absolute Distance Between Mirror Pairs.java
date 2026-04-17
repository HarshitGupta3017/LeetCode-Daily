// Solution for Minimum Absolute Distance Between Mirror Pairs in JAVA

class Solution {
    public int minMirrorPairDistance(int[] nums) {
        Map<Integer, Integer> reverseIndexMap = new HashMap<>();
        int minimumDistance = Integer.MAX_VALUE;

        for (int currentIndex = 0; currentIndex < nums.length; currentIndex++) {
            int currentValue = nums[currentIndex];

            // Check if current value matches any previously stored reversed value
            if (reverseIndexMap.containsKey(currentValue)) {
                int previousIndex = reverseIndexMap.get(currentValue);
                minimumDistance = Math.min(minimumDistance, currentIndex - previousIndex);
            }

            // Store reversed value
            int reversedValue = getReversedNumber(currentValue);
            reverseIndexMap.put(reversedValue, currentIndex);
        }

        return (minimumDistance == Integer.MAX_VALUE) ? -1 : minimumDistance;
    }

    private int getReversedNumber(int number) {
        StringBuilder sb = new StringBuilder(String.valueOf(number));
        sb.reverse();
        return Integer.parseInt(sb.toString()); // removes leading zeros
    }
}
