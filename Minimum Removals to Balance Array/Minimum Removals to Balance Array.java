// Solution for Minimum Removals to Balance Array in JAVA

class Solution {
    public int minRemoval(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length, left = 0, best = 1;

        for (int right = 0; right < n; right++) {
            while (left <= right && (long) nums[right] > (long) k * nums[left]) {
                left++;
            }
            best = Math.max(best, right - left + 1);
        }
        return n - best;
    }
}
