// Solution for Count of Interesting Subarrays in JAVA

class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        int prefix = 0;
        long res = 0;
        Map<Integer, Long> freq = new HashMap<>();
        freq.put(0, 1L);
        for (int num: nums) {
            if (num % modulo == k) prefix++;
            int modPrefix = prefix % modulo;
            int prevPrefix = (modPrefix - k + modulo) % modulo;
            if (freq.containsKey(prevPrefix)) res += freq.get(prevPrefix);
            freq.put(modPrefix, freq.getOrDefault(modPrefix, 0L) + 1);
        }
        return res;
    }
}
