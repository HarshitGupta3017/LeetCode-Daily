// Solution for Minimum Distance Between Three Equal Elements II in JAVA

class Solution {
    public int minimumDistance(int[] nums) {
        Map<Integer, int[]> map = new HashMap<>();
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            int val = nums[i];

            if (map.containsKey(val)) {
                int[] p = map.get(val);

                if (p[0] != -1) {
                    ans = Math.min(ans, 2 * (i - p[0]));
                }

                map.put(val, new int[]{p[1], i});
            } else {
                map.put(val, new int[]{-1, i});
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
