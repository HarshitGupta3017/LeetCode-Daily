// Solution for Longest Balanced Subarray I in JAVA

class Solution {
    public int longestBalanced(int[] nums) {

        int n = nums.length;
        int maxBalancedLength = 0;

        // Fix the starting index
        for (int start = 0; start < n; start++) {

            // Sets to track DISTINCT evens and odds
            Set<Integer> distinctEven = new HashSet<>();
            Set<Integer> distinctOdd = new HashSet<>();

            // Extend subarray to the right
            for (int end = start; end < n; end++) {

                if (nums[end] % 2 == 0) {
                    distinctEven.add(nums[end]);
                } else {
                    distinctOdd.add(nums[end]);
                }

                // Check balanced condition
                if (distinctEven.size() == distinctOdd.size()) {
                    maxBalancedLength = Math.max(
                        maxBalancedLength,
                        end - start + 1
                    );
                }
            }
        }

        return maxBalancedLength;
    }
}
