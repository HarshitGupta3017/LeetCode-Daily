// Solution for Count Equal and Divisible Pairs in an Array in JAVA

class Solution {
    public int countPairs(int[] nums, int k) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        int n = nums.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (mp.containsKey(num)) {
                for (int prev_idx: mp.get(num)) {
                    if ((prev_idx * i) % k == 0) count++;
                }
            }
            mp.computeIfAbsent(num, x -> new ArrayList<>()).add(i);
        }
        return count;
    }
}
