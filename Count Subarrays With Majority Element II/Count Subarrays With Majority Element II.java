// Solution for Count Subarrays With Majority Element II in JAVA

class Solution {
    public long countMajoritySubarrays(int[] nums, int target) {

        Map<Integer, Integer> prefixFreq = new HashMap<>();
        prefixFreq.put(0, 1);

        int prefixSum = 0, validLeftCount = 0;
        long result = 0;

        for (int num : nums) {
            if (num == target) {
                validLeftCount += prefixFreq.getOrDefault(prefixSum, 0);
                prefixSum++;
            } else {
                prefixSum--;
                validLeftCount -= prefixFreq.getOrDefault(prefixSum, 0);
            }

            prefixFreq.put(prefixSum, prefixFreq.getOrDefault(prefixSum, 0) + 1);
            result += validLeftCount;
        }

        return result;
    }
}
