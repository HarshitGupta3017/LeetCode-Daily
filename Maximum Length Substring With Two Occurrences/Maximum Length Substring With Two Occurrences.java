// Solution for Maximum Length Substring With Two Occurrences in JAVA

class Solution {
    public int maximumLengthSubstring(String s) {
        int left = 0, right = 0;
        int maxLen = 0;
        int[] freq = new int[26];

        while (right < s.length()) {
            freq[s.charAt(right) - 'a']++;

            while (freq[s.charAt(right) - 'a'] > 2) {
                freq[s.charAt(left) - 'a']--;
                left++;
            }

            maxLen = Math.max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
}
