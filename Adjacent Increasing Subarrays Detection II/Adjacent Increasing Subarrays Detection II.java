// Solution for Adjacent Increasing Subarrays Detection II in JAVA

class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int prev = 0, curr = 1, maxK = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.get(i) > nums.get(i - 1)) curr++;
            else { prev = curr; curr = 1; }
            maxK = Math.max(maxK, Math.max(curr / 2, Math.min(prev, curr)));
        }
        return maxK;
    }
}
