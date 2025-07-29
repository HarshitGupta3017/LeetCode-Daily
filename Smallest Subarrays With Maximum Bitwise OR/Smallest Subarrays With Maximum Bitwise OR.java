// Solution for Smallest Subarrays With Maximum Bitwise OR in JAVA

class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int[] latestBitPosition = new int[32];
        Arrays.fill(latestBitPosition, -1);

        for (int i = n - 1; i >= 0; i--) {
            int farthestReach = i;
            for (int bit = 0; bit < 32; bit++) {
                if ((nums[i] & (1 << bit)) == 0) {
                    if (latestBitPosition[bit] != -1) {
                        farthestReach = Math.max(farthestReach, latestBitPosition[bit]);
                    }
                } else {
                    latestBitPosition[bit] = i;
                }
            }
            result[i] = farthestReach - i + 1;
        }

        return result;
    }
}
