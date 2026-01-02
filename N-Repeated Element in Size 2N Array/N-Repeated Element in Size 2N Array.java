// Solution for N-Repeated Element in Size 2N Array in JAVA

class Solution {
    public int repeatedNTimes(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (seen.contains(num)) {
                return num;
            }
            seen.add(num);
        }
        return 0; 
    }
}
