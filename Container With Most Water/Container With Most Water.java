// Solution for Container With Most Water in JAVA

class Solution {
    public int maxArea(int[] h) {
        int l = 0, r = h.length - 1, res = 0;
        while (l < r) {
            res = Math.max(res, (r - l) * Math.min(h[l], h[r]));
            if (h[l] < h[r]) l++;
            else r--;
        }
        return res;
    }
}
