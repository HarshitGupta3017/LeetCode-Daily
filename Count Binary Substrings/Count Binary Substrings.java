// Solution for Count Binary Substrings in JAVA

class Solution {
    public int countBinarySubstrings(String s) {

        int totalSubstrings = 0;

        // Length of the previous consecutive group (e.g., "000")
        int previousGroupLength = 0;

        // Length of the current consecutive group
        int currentGroupLength = 1;  // First character starts a group

        // Start from second character
        for (int i = 1; i < s.length(); i++) {

            if (s.charAt(i) == s.charAt(i - 1)) {
                // Still in the same group → increase current group length
                currentGroupLength++;
            } else {
                // Group changed (0→1 or 1→0)

                // Add valid substrings from adjacent groups
                totalSubstrings += Math.min(previousGroupLength, currentGroupLength);

                // Shift current group to previous
                previousGroupLength = currentGroupLength;

                // Reset current group length
                currentGroupLength = 1;
            }
        }

        // Add the last pair of groups
        totalSubstrings += Math.min(previousGroupLength, currentGroupLength);

        return totalSubstrings;
    }
}
