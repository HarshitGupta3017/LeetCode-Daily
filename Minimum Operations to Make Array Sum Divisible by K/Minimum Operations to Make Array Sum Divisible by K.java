// Solution for Minimum Operations to Make Array Sum Divisible by K in JAVA

class Solution {
    public int minOperations(int[] nums, int k) {
        return Arrays.stream(nums).sum() % k;
    }
}
