// Solution for Minimum Time to Repair Cars in JAVA

class Solution {

    private boolean isPossible(int[] ranks, int cars, long mid) {
        long carsFixed = 0;
        for (int i = 0; i < ranks.length; i++) {
            carsFixed += Math.sqrt(mid / ranks[i]);
        }
        return carsFixed >= cars;
    }

    public long repairCars(int[] ranks, int cars) {
        int maxR = Arrays.stream(ranks).max().getAsInt();
        long l = 1, r = (long) maxR * cars * cars;
        long res = -1;
        while (l <= r) {
            long mid = l + (r - l) / 2;
            if (isPossible(ranks, cars, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
}
