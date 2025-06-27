// Solution for Longest Subsequence Repeated k Times in JAVA

class Solution {

    // Helper to check if 'sub' repeated k times is a subsequence of 's'
    private boolean isSubsequence(String s, StringBuilder sub, int k) {
        int i = 0, j = 0;
        int len = sub.length();
        int n = s.length();
        while (i < n && j < len * k) {
            if (s.charAt(i) == sub.charAt(j % len)) {
                j++;
            }
            i++;
        }
        return j == len * k;
    }

    // Backtracking to generate lexicographically largest string of maxLen using available characters
    private boolean backtrack(String s, StringBuilder curr, boolean[] usable, int[] remainingFreq, int maxLen, int k, String[] result) {
        if (curr.length() == maxLen) {
            if (isSubsequence(s, curr, k)) {
                result[0] = curr.toString();
                return true;
            }
            return false;
        }

        for (int i = 25; i >= 0; i--) {
            if (!usable[i] || remainingFreq[i] == 0) continue;
            char ch = (char) (i + 'a');
            curr.append(ch);
            remainingFreq[i]--;

            if (backtrack(s, curr, usable, remainingFreq, maxLen, k, result))
                return true;

            curr.deleteCharAt(curr.length() - 1);
            remainingFreq[i]++;
        }
        return false;
    }

    public String longestSubsequenceRepeatedK(String s, int k) {
        int n = s.length();
        int[] freq = new int[26];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        boolean[] usable = new boolean[26];
        int[] maxAvailable = new int[26];
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                usable[i] = true;
                maxAvailable[i] = freq[i] / k;
            }
        }

        int maxPossibleLength = n / k;
        String[] result = new String[1];
        result[0] = "";

        for (int len = maxPossibleLength; len >= 0; len--) {
            int[] remainingFreq = maxAvailable.clone();
            StringBuilder curr = new StringBuilder();
            if (backtrack(s, curr, usable, remainingFreq, len, k, result))
                return result[0];
        }

        return "";
    }
}
