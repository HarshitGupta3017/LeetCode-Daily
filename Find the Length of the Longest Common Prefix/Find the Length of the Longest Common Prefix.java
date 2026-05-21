// Solution for Find the Length of the Longest Common Prefix in JAVA

class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {

        Set<Integer> prefixes = new HashSet<>();
        int longest = 0;

        // Store all prefixes from arr1
        for (int num : arr1) {
            while (num > 0 && !prefixes.contains(num)) {
                prefixes.add(num);
                num /= 10;
            }
        }

        // Check prefixes in arr2
        for (int num : arr2) {

            while (num > 0 && !prefixes.contains(num)) {
                num /= 10;
            }

            if (num > 0) {
                longest = Math.max(
                    longest,
                    String.valueOf(num).length()
                );
            }
        }

        return longest;
    }
}
