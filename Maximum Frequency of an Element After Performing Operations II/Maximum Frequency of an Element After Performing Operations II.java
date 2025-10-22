// Solution for Maximum Frequency of an Element After Performing Operations II in JAVA

class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int maxVal = Arrays.stream(nums).max().getAsInt() + k;

        TreeMap<Integer, Integer> diffMap = new TreeMap<>();
        HashMap<Integer, Integer> freq = new HashMap<>();

        // Build range contribution map
        for (int val : nums) {
            freq.put(val, freq.getOrDefault(val, 0) + 1);
            int left = Math.max(val - k, 0);
            int right = val + k;

            diffMap.put(left, diffMap.getOrDefault(left, 0) + 1);
            diffMap.put(right + 1, diffMap.getOrDefault(right + 1, 0) - 1);
            diffMap.putIfAbsent(val, 0);
        }

        int maxFreq = 1, prefix = 0;

        // Traverse sorted keys
        for (int key : diffMap.keySet()) {
            prefix += diffMap.get(key);
            int currFreq = freq.getOrDefault(key, 0);
            int convertible = prefix - currFreq;
            int used = Math.min(numOperations, convertible);
            maxFreq = Math.max(maxFreq, currFreq + used);
        }

        return maxFreq;
    }
}
