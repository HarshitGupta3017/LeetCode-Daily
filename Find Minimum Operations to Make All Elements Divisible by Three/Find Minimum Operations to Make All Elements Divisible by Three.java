// Solution for Find Minimum Operations to Make All Elements Divisible by Three in JAVA

class Solution {
    public int minimumOperations(int[] nums) {
        int ops = 0;
        for (int num: nums) {
            ops += (num % 3 != 0) ? 1 : 0;
        }
        return ops;
    }
}
