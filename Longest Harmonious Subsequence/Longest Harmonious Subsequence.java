// Solution for Longest Harmonious Subsequence in JAVA

class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> freqMap = new HashMap<>();

        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        int maxLength = 0;

        for (int num : freqMap.keySet()) {
            if (freqMap.containsKey(num + 1)) {
                int currentLength = freqMap.get(num) + freqMap.get(num + 1);
                maxLength = Math.max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
}
