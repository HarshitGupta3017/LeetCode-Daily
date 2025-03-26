// Solution for Minimum Operations to Make a Uni-Value Grid in JAVA

class Solution {
    public int minOperations(int[][] grid, int x) {
        List<Integer> nums = new ArrayList<>();
        for (int[] row: grid) {
            for (int col: row) {
                nums.add(col);
            }
        }
        int remainder = nums.get(0) % x;
        for (int num: nums) {
            if (num % x != remainder) return -1;
        }
        Collections.sort(nums);
        int ops = 0;
        int median = nums.get(nums.size() / 2);
        for (int num: nums) {
            ops += Math.abs(num - median) / x;
        }
        return ops;
    }
}
