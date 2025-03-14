// Solution for Maximum Candies Allocated to K Children in JAVA

class Solution {
    public int maximumCandies(int[] candies, long k) {
        int l = 1, r = Arrays.stream(candies).max().getAsInt();
        int res = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long count = 0;
            for (int c: candies) {
                count += (c / mid);
                if (count >= k) break;
            }
            if (count >= k) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
}
