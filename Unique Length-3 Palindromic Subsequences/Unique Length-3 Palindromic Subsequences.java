// Solution for Unique Length-3 Palindromic Subsequences in JAVA

class Solution {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();

        // Store first and last index for each character
        int[][] charBounds = new int[26][2];
        for (int i = 0; i < 26; i++) {
            charBounds[i][0] = -1;  // first index
            charBounds[i][1] = -1;  // last index
        }

        // Record first and last occurrence
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';

            if (charBounds[idx][0] == -1)
                charBounds[idx][0] = i;

            charBounds[idx][1] = i;
        }

        int result = 0;

        // For each character, collect unique middle chars
        for (int c = 0; c < 26; c++) {
            int leftIndex = charBounds[c][0];
            int rightIndex = charBounds[c][1];

            if (leftIndex == -1) continue;

            HashSet<Character> middleChars = new HashSet<>();

            for (int mid = leftIndex + 1; mid < rightIndex; mid++) {
                middleChars.add(s.charAt(mid));
            }

            result += middleChars.size();
        }

        return result;
    }
}
