// Solution for Longest Balanced Substring I in JAVA

class Solution {

    public int longestBalanced(String s) {

        int n = s.length();
        int maxLength = 0;

        // Fix starting index
        for (int start = 0; start < n; start++) {

            int[] frequency = new int[26];

            for (int end = start; end < n; end++) {

                // Update frequency
                frequency[s.charAt(end) - 'a']++;

                if (isBalanced(frequency)) {
                    maxLength = Math.max(maxLength, end - start + 1);
                }
            }
        }

        return maxLength;
    }

    // Helper method
    private boolean isBalanced(int[] freq) {

        int requiredFrequency = 0;

        for (int i = 0; i < 26; i++) {

            if (freq[i] == 0)
                continue;

            if (requiredFrequency == 0) {
                requiredFrequency = freq[i];
            } else if (freq[i] != requiredFrequency) {
                return false;
            }
        }

        return true;
    }
}
