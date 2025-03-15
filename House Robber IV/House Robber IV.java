// Solution for House Robber IV in JAVA

class Solution {

    private boolean isPossible(int[] nums, int mid, int k, int n) {
        int house = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                house++; // included
                i++; // moved to i + 2
            }
        }
        return house >= k; // got atleast k houses
    }

    public int minCapability(int[] nums, int k) {
        int n = nums.length;
        int l = Arrays.stream(nums).min().getAsInt();
        int r = Arrays.stream(nums).max().getAsInt();
        int res = r;
        while (l <= r) {
            int mid = l + (r - l) / 2; // capability
            if (isPossible(nums, mid, k, n)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
}
