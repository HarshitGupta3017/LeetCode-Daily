// Solution for Count Subarrays With Majority Element I in JAVA

class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;
        int result = 0;

        for (int left = 0; left < n; left++) {
            int targetCount = 0;

            for (int right = left; right < n; right++) {
                if (nums[right] == target) {
                    targetCount++;
                }

                int subarrayLen = right - left + 1;

                // target is a majority if it appears more than half the time
                if (targetCount * 2 > subarrayLen) {
                    result++;
                }
            }
        }

        return result;
    }
}
