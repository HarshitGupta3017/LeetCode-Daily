// Solution for Smallest Missing Multiple of K in JAVA

class Solution {
    public int missingMultiple(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) set.add(num);

        int candidate = k;
        while (set.contains(candidate))
            candidate += k;

        return candidate;
    }
}
